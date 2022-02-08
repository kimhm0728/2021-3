# iris 데이터셋 파악하기
class(iris)
str(iris)
head(iris)

# Species를 제외한 iris 데이터 추출
irisKmeans <- iris[,-5]

# k-means 를 통해 종을 분류 (k=3)
result <- kmeans(irisKmeans, 3)

# 실제 Species와 예측한 결과를 비교
table(iris$Species, result$cluster)

# 예측결과를 산점도로 그리기
par(mfrow=c(1,2)) # x = 1, y = 2로 그래프를 배치
plot(iris[,1:2], col=result$cluster) # 꽃받침의 길이와 폭에 대한 종 분류
points(result$centers[,1:2], col = 1:3, pch = 16) # 중앙값을 표시

plot(iris[,3:4], col=result$cluster) # 꽃잎의 길이와 폭에 대한 종 분류
points(result$centers[,3:4], col = 1:3, pch = 16) # 중앙값을 표시

# 모든 변수의 산점도를 한꺼번에 표현
plot(iris[,1:4], pch = result$cluster, col = result$cluster)