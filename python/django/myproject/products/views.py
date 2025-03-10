from django.shortcuts import render

# .model is used to relative path
from .models import Product 
from .forms import ProductForm
# Create your views here.

def show_product(request) :

    form  = ProductForm(request.POST or None)
    if form.is_valid() :
        form.save()
    products = Product.objects.all() # return a  QuerySet (list of all Product obj.)

    # combines the "product.html" and {context_dict} and returns the result
    # to  request (user)
    return render(request,"product.html",{"products":products}) 

        