from django.db import models
#
# Create your models here. se crean singularizados 
class Sensor(models.Model):
    name=models.CharField(max_length=50)
    humidity = models.FloatField(default=0)
