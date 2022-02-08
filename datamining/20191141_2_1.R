# txt 파일 불러오기
TrafficAccident <- read.csv(file="C:/DataMining/2016_TA.txt", header = T)

# TrafficAccident 데이터셋 파악하기
class(TrafficAccident)
str(TrafficAccident)
head(TrafficAccident)
TrafficAccident

# 월별 사망자수에 대한 막대 그래프
library(ggplot2)
ggplot(TrafficAccident, aes(x=월, y=사망자수)) + geom_bar(stat="identity", width=0.7, fill="steelblue")
  
# 월별 발생건수에 대한 boxplot
boxplot(발생건수~월, data=TrafficAccident)

# 시도별 사망자수에 대한 boxplot
boxplot(사망자수~시도, data=TrafficAccident)

# 사망자수에 대한 boxplot
boxplot(TrafficAccident$사망자수)

# 이상치 확인하기
out.value <- boxplot(TrafficAccident$사망자수)$out
out.value

newTrafficAccident <- TrafficAccident 
newTrafficAccident$사망자수[newTrafficAccident$사망자수 %in% out.value] = NA # 이상치에 해당하는 값을 결측값 처리
newTrafficAccident <- newTrafficAccident[complete.cases(newTrafficAccident),] # 결측값을 제거

# 이상치를 제거한 후 사망자수에 대한 boxplot
boxplot(newTrafficAccident$사망자수)
