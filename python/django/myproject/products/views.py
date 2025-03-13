from django.http import Http404
from django.shortcuts import render , get_object_or_404 , redirect


# .model is used to relative path
from .models import Product 
from .forms import ProductForm , RawProductForm
# Create your views here.

def product_create_view(request) :
    initial_data = {
        "title" : "this is an initial title" ,
        "desc" : "this is an initial desc" ,
        "price" : 69.99 
    }
    my_form = RawProductForm(initial=initial_data) # pass the initial data 
    if request.method == "POST" :
        my_form = RawProductForm(request.POST,initial=initial_data) # pass the initial data 
        if my_form.is_valid() :
            print(my_form.cleaned_data)
            Product.objects.create(**my_form.cleaned_data) 
            # use double asterisk to convert dict. format into valid format  
        else :
            print(my_form.errors)
    context = {
        "form" : my_form
    }
    return render(request,"product_new.html",context)

def form_view(request) :
    form = ProductForm(request.POST or None)
    context = {}
    return render(request,'product_new.html',context)

def dynamic_page_view(request,my_id) :
    try :
        obj = Product.objects.get(id=my_id)
    except Product.DoesNotExist :
        raise Http404

    context ={
        "obj" : obj
    }
    return render(request,"product.html",context)


# def form_view(request) :
#     form = ProductForm(request.POST or None)
#     if form.is_valid() :  # only save if the form is valid 
#         form.save() 
#     context = { 
#         'form' : form 
#     }
#     return render(request,'product_new.html',context)

def show_product(request) :

    products = Product.objects.all() # return a  QuerySet (list of all Product obj.)

    # combines the "product.html" and {context_dict} and returns the result
    # to  request (user)
    return render(request,"product.html",{"products":products}) 


def product_delete_view(request,product_id) :
    obj = get_object_or_404(Product,id=product_id)
    if request.method == "POST" :
        # when the POST request is triggered , do this 
        obj.delete()
        return redirect('../../admin')
    return render(request,'delete.html',{"obj":obj}) 