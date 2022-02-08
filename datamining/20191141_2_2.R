# 패키지와 데이터프레임 가져오기
library(mlbench)
data(BreastCancer)

# BreastCancer 데이터셋 파악하기
class(BreastCancer)
str(BreastCancer)
head(BreastCancer)

# 결측값 제거하여 newBreastCancer에 저장
newBreastCancer <- BreastCancer[complete.cases(BreastCancer),]

# benign인 데이터 200개 추출
benign <- subset(newBreastCancer, Class == "benign") # subset을 통해 benign인 행 추출
benign.idx <- sample(nrow(benign), 200, replace = FALSE) # 200개의 인덱스 비복원추출
benign <- benign[benign.idx, ] # 인덱스에 해당하는 실제 데이터를 저장

# malignant인 데이터 200개 추출
malignant <- subset(newBreastCancer, Class == "malignant") # subset을 통해 malignant인 행 추출
malignant.idx <- sample(nrow(malignant), 200, replace = FALSE) # 200개의 인덱스 비복원추출
malignant <- malignant[malignant.idx, ] # 인덱스에 해당하는 실제 데이터를 저장

# 데이터셋 합치기
newBreastCancer <- rbind(benign, malignant)

# 패키지 가져오기
require("class")

# 정규화 함수
normal <- function(x) {
  return((x-min(x))/(max(x)-min(x)))
}

# 숫자형으로 변경
for(i in 1:10) {
  newBreastCancer[,i] <- as.numeric(newBreastCancer[,i])
}

boxplot(newBreastCancer) # 데이터의 범위 확인
scaleBreastCancer <- as.data.frame(lapply(newBreastCancer[,1:10], normal)) # 데이터를 정규화
boxplot(scaleBreastCancer) # 정규화 후 데이터의 범위 확인

### knn Classification ###

tr.idx <- seq(2, 400, 2) # 짝수 인덱스
ds.tr <- scaleBreastCancer[tr.idx, 1:10] # 학습 셋
ds.ts <- scaleBreastCancer[-tr.idx, 1:10] # 테스트 셋
cl.tr <- factor(newBreastCancer[tr.idx, 11]) # 학습 셋의 정보
cl.ts <- factor(newBreastCancer[-tr.idx, 11]) # 테스트 셋의 정보

pred <- knn(ds.tr, ds.ts, cl.tr, k = 3, prob = TRUE) # 예측

acc <- mean(pred==cl.ts) # 예측 정확도
acc

# 예측 결과를 표로 표현
table(pred, cl.ts)
# TP FP
# FN TN

### 10-fold cross validation ###

group.1 <- cut(seq(1,200), breaks=10, labels=FALSE) # benign의 인덱스를 10개로 나눔
group.2 <- cut(seq(201,400), breaks=10, labels=FALSE) # malignant의 인덱스를 10개로 나눔
fold <- c(group.1, group.2) # 합치기 

acc <- c() # 정확도를 저장하기 위한 공팩터 생성
for (i in 1:10) {
  ds.tr <- scaleBreastCancer[fold != i, 1:10] # 학습 셋
  ds.ts <- scaleBreastCancer[fold == i, 1:10] # 테스트 셋
  cl.tr <- factor(newBreastCancer[fold !=i, 11]) # 학습 셋의 정보
  cl.ts <- factor(newBreastCancer[fold == i, 11]) # 테스트 셋의 정보
  pred <- knn(ds.tr, ds.ts, cl.tr, k=3) # 예측
  acc[i] <- mean(pred==cl.ts) # 예측 정확도
}

acc
mean(acc) # 정확도의 평균