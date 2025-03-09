from django.http import HttpResponse  #import to get send_response 
from django.shortcuts import render

# Create your views here.

def homepage_view(request) :
    print(request.user) # shows the user_name who is requesting 
    return render(request,"home.html",{})

def contact_view(request,*args,**kwargs) :
    my_dict = {
        "my_id"   : "41123" ,
        "my_dept" : "cse" ,
        "my_name" : "hasan" 
    }
    my_list = ["310","309","308","302"] 
    print(request.user) 
    return render(request,"contact.html",my_dict)


def social_view(request) :
    print(request.user)
    return HttpResponse("<h1>welcome to social</h1>")