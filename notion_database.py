import requests, json
from datetime import datetime, timezone



NOTION_KEY = 'secret_htHPxsbrk8GYU9p5h92b7FKlVyISxWFYZtl84fpYUcq'
DATABASE_ID = '13850e2e5d3349d0948eef448e954b42'

headers = {
    "Authorization": "Bearer " + NOTION_KEY,
    "Content-Type": "application/json",
    "Notion-Version": "2022-02-22",
}


def create_page(data: dict):
    create_url = "https://api.notion.com/v1/pages"


    res = requests.post(create_url, headers=headers, data=data)
    # print(res.status_code)
    return res

def programming_language(lst):
    dic = {"multi_select" : []}
    print(lst)
    for i in lst:
        dic["multi_select"].append({"name": i})
    print(dic)
    return dic

def problem_tag(args):
    dic = {
        "multi_select" : []}
    for i in args:
        dic["multi_select"].append({"name": i})
    print(dic)
    return dic

title = "Test Title"
description = "Test Description"
published_date = datetime.now().astimezone(timezone.utc).isoformat()
end_date = datetime.now().date()


### 
print('사용 언어를 말하세요')
lst_language = list(map(str, input().split()))
print('문제 태그를 말하세요')
tag_arg = list(map(str, input().split()))
 
data = {
    "parent": {"database_id": DATABASE_ID},
    "created_time" : f'{published_date}',
    "properties" : {
        
        
        "Due date": {
            "id": "M%3BBw",
            "type": "date",
            "date": {
                "start": str(end_date),
                "end": None,
                "time_zone": None
            }
        },
        
        "Programming language": programming_language(lst_language),
        "Problem tag": problem_tag(tag_arg),
        
        "title" : {
            "title" : [
                {
                'text':{
                    "content" : input()
                        }
                    }
                ]
            }

        }
    }

data = json.dumps(data)

created_time  = {}


print(create_page(data).text) 