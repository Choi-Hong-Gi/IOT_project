import urllib.request
import json
from time import localtime, strftime
import datetime


dic = {"T1H":"Temperature", "RN1":"RainProbability", "UUU":"Wind EtoW", "VVV":"Wind StoN", "REH":"Humidity",
       "PTY":"Precipitation(Rain) Type", "VEC":"Wind Direction", "WSD":"Wind Speed"}

url = 'http://apis.data.go.kr/1360000/VilageFcstInfoService_2.0/getUltraSrtNcst'
serviceKey = 'ServiceKey=' + '5LMImuDe4KYWVHN%2BC8ZiRhKnnboWUFJjia05xmbVjuw79Gv5upIZD%2BB03TgGptciKHQAYkX5TNgTptdIAqJYPg%3D%3D'
pageNo = '&pageNo=1'
numOfRows = '&numOfRows=1000'
dataType = '&dataType=JSON'

current = datetime.datetime.now()
base_date = '&base_date=' + current.strftime("%Y%m%d")
if localtime().tm_min>30:
    base_time = '&base_time=' + current.strftime("%H00")
else:
    current = current - datetime.timedelta(hours=1)
    base_time = '&base_time=' + current.strftime("%H00")
    
nx = '&nx=68'
ny = '&ny=109'
    
queryParams = '?' + serviceKey + pageNo + numOfRows + dataType + base_date + base_time + nx + ny

response = urllib.request.urlopen(url+queryParams).read().decode('utf8')

weather = json.loads(response)
totalCount = weather["response"]["body"]["totalCount"]
for k in weather["response"]["body"]["items"]["item"]:
    print(dic[k["category"]]," : ",k["obsrValue"])