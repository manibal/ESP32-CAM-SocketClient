# ESP32-CAM-SocketClient
ESP32-CAM-SocketCliente / Python OpenCV socket Server Object Detection
La idea base del proyecto es crear una camara de seguridad economica y que genere alarmas por movimiento de personas o autos que sea confiable con muy pocas falsas alarmas. y que envie la informacion a un servidor remoto sin necesidad de que se abran puertos (firewall transparent)


# ESP32-CAM Socket Client
Que el esp32-cam sea cliente socket permite que el dispositivo salga a traves de cualquier firewall hacia internet sin necesidad de redireccionar puertos, es mas se puede utilizar una url para que determine la ip.
TODO: Que busque comandos y la ip final de transmision en un servidor remoto
TODO: Mejorar la velocidad de transmision de datos, capaz compilando con esspif

# Python Socket Server con OPEN CV y YOLO (Thanks https://github.com/balajisrinivas/Object-Detection-on-images-using-YOLO)
Servidor que recibe las imagenes y mediante Yolo detecta objetos, dentro de los algoritmos que probe es el mas rapido y el que mejor detecta los objetos.
TODO: que yolo solo detecte personas y autos.
TODO: que cuando detecte una persona envie mensajes via telegram con activacion y desactibacion mediante comandos telegram y/o agenda de tiempos
TODO: que sirva como servidor para conectar con una aplicacion en el celular, ya estando en la nube es posible que sirva de videro server para apps
TODO: Mejorar el rendimiento, la velocidad es pobre y con retraso de la imagen.

Toda la ayuda e ideas que me puedan dar son bienvenidas.
