from django import forms 

from .models import Product

# raw html form 
class ProductForm(forms.ModelForm) :
    class Meta : # this class help to easily create form field from app_model
        model = Product   # app_model
        fields = [
            'title' , 'desc' , 'price' , 'summary'
        ]

# raw django form
class RawProductForm(forms.Form) :  

    title = forms.CharField(label='title',widget=forms.Textarea(
        attrs={
            "placeholder" : "title of product" ,
            "rows" : 5 ,
            "cols" : 50 
        }
    ))
    desc  = forms.CharField(required=False,widget=forms.Textarea(
        attrs={
            "class" : "class-for-desc" ,
            "id"  : "id-for-desc" ,
            "rows" : 20 , 
            "cols" : 120 
        }
    ))
    price = forms.DecimalField(initial=199.99) 

    def clean_title(self,*args,**kwargs) : # this "clean_title" name has to be specific , because the form invokes it auto
        title = self.cleaned_data.get("title") 
        if "savoy" == title : # custom field validation for title 
            return title 
        else :
            raise forms.ValidationError("this is not a valid title.") 