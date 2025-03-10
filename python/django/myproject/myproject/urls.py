"""
URL configuration for myproject project.

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/5.1/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.contrib import admin
from django.urls import path

# importing the functions for page rendering 
from pages.views import homepage_view , contact_view , social_view
from products.views import show_product

urlpatterns = [
    # custom url routing 
    # declaring  page_path and which func. will render that page 
    path('contact/', contact_view, name='contact') ,
    path('home/', homepage_view, name='home') ,
    path('', homepage_view, name='home') ,
    path('social/', social_view, name='social') ,
    path('product/',show_product , name='product list') ,

    # default url 
    path('admin/', admin.site.urls),
]
