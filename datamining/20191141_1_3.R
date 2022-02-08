# 패키지와 데이터프레임 가져오기
library(mlbench)
data(BostonHousing)

# BostonHousing 데이터셋 파악하기
class(BostonHousing)
str(BostonHousing)
head(BostonHousing)

# chas 변수를 제외한 데이터 추출
newBostonHousing <- BostonHousing[,-4]

# 선형 회귀 모델
model1 <- lm(medv~., data=newBostonHousing)

# 모델 평가
summary(model1) 

# MASS 패키지 로드하기 (stepAIC 함수 사용을 위해)
library(MASS)

# model 분석 
# 종속변수 medv를 예측하는데 도움이 되는 변수들을 찾기
step <- stepAIC(model1, direction="both")

# 새로운 선형 회귀 모델 생성
model2 <- lm(medv~crim + zn + nox + rm + dis + rad + tax + ptratio + b + lstat, data=newBostonHousing)

# 모델 평가
summary(model2)