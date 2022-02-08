# 패키지와 데이터프레임 가져오기
library(mlbench)
data(Ozone)

# Ozone 데이터셋 파악하기
class(Ozone)
str(Ozone)
head(Ozone)

# 산점도
# 독립변수가 기온(V8), 종속변수가 오존 농도(V4) 
plot(V4~V8, data=Ozone)

# 선형 회귀모델
model <- lm(V4~V8, Ozone)
model

# 회귀식을 산점도에 표현
abline(coef(model))

# Intercept: b, V8:W
b <- coef(model)[1] # -14.8419
W <- coef(model)[2] # 0.4272

# 오존 농도 예측
# 기온이 30일 때
V8 = 30
V4 = W * V8 + b # 회귀식
print(V4)

# 기온이 40일 때
V8 = 40
V4 = W * V8 + b 
print(V4)

# 기온이 50일 때
V8 = 50
V4 = W * V8 + b 
print(V4)
