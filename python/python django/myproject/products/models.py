from django.db import models

# Create your models here.


class Product(models.Model) :
	# format the models as per req.
	title   = models.CharField(max_length=120)
	desc    = models.TextField(blank=True,null=True)
	price   = models.DecimalField(decimal_places=2,max_digits=100)
	summary = models.TextField(blank=False,default="cool")
	featured = models.BooleanField()