import numpy as np
import matplotlib.pyplot as plt
import os
from scipy.io.wavfile import write

os.makedirs("./fijas")
os.makedirs("./perturbada")
datos= np.loadtxt("datos.dat")
datos1= np.loadtxt("datos1.dat")
x=np.linspace(0,0.64,130)


print(len(x))
print(len(datos[0,:]))
for i in range(0,4):
    plt.figure(figsize=(10,10))
    plt.plot(x,datos[i,:])
    plt.xlim((0,0.7))
    plt.ylim((-0.02,0.02))
    if(i==0):
	plt.title("cuerda fija en 0")
    elif(i==1):
	plt.title("cuerda fija en T/8")
    elif(i==2):
	plt.title("cuerda fija en T/4")
    elif(i==3):
	plt.title("cuerda fija en T/2")
    plt.savefig("./fijas/"+str(i)+".jpg")
    plt.close()

for i in range(4,8):
    plt.figure(figsize=(10,10))
    plt.plot(x,datos[i,:])
    plt.xlim((0,0.7))
    plt.ylim((-2,2))
    if(i==4):
	plt.title("cuerda perturbada  en 0")
    elif(i==5):
	plt.title("cuerda perturbada en T/8")
    elif(i==6):
	plt.title("cuerda perturbada  en T/4")
    elif(i==7):
	plt.title("cuerda perturbada en T/2")
    plt.savefig("./perturbada/"+str(i)+".jpg")
    plt.close()

os.system("sudo apt-get install imagemagick")
os.chdir("./perturbada")
os.system("convert -delay 20 -loop 0 *.jpg cuerdaPerturbada.gif")

os.chdir("..")

os.chdir("./fijas")
os.system("convert -delay 20 -loop 0 *.jpg cuerdaFija.gif")
os.chdir("..")

data=datos[0,:]
fs=len(data)
out_f = 'out.wav'
scaled = np.int16(data/np.max(np.abs(data)) * 32767)
write('sonido.wav', 44100, scaled) ## sacado codigo para hacer sonido de https://stackoverflow.com/questions/10357992/how-to-generate-audio-from-a-numpy-array .



