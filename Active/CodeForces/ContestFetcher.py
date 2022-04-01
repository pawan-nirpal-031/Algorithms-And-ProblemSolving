import requests

url = "http://codeforces.com/api"
options = '/contest.list'
link = 'http://codeforces.com/contest/'

data = requests.get(url+options)
data = data.json()
Div3 = 'Div. 3'
Div2 = 'Div. 2'
Educational = 'Educational'
Contests = {Div3:"Divison_3.txt",Div2:"Divison_2.txt",Educational:"Educational_Round.txt"}



def CodeforcesContestFetcher(contest_name,contest_links,data):
    if(data['status']=='OK'):
        data = data['result']
        for cont in data:
           if (contest_name in cont['name']):
               contest_links.append(int(cont['id']))
        contest_links.sort()
        links_file = open(Contests[contest_name],"w+")
        num = 1
        if(len(contest_links)==0):
            print("Unable to fetch links, aborting... ")
            return
        for cont in contest_links:
            links_file.write(str(num)+" : "+link+str(cont)+'\n')
            num+=1
        links_file.close()
    else :
        print("Unexpected error occured, try after a few moments")




Div3Contest = []
Div2Contest = []
EducationalContest = []


CodeforcesContestFetcher(Div3,Div3Contest,data)





        

