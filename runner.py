import csv
import requests
import time
def csv_reader(file_obj):
	bb=0
	reader= csv.reader(file_obj)
	for row in reader:
		a,b,c=str(row).split(",")
		a=a.split('"')[0]
		c=c.split('"')[0]
		r=requests.post("https://hooks.zapier.com/hooks/catch/3120866/kplm71/?temperature="+b+"&moisture="+c+"&light="+a+"&warning=10")
		print(r.status_code, r.reason)	
		time.sleep(5)
		if (bb := bb+1)==2:
			print("Great job shardul")
			break	
if __name__=="__main__":
	csv_path='shardul.csv'
	with open("teraterm2.csv","rb") as f_obj:
		csv_reader(f_obj)
