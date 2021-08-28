[Variables]
R=(20*#scale#)


Scale=1
PLayer=WNP
NPName=Spotify

ColorMode=0
OppositeColor=255,255,255
MainColor=12,12,12

Style=Side

;RenderBlur (Brightness, Saturation, Hue)
BlurModulate=(#ColorMode# = 1 ? 80 : 120),70,100
BlurRadius=30
BlurSigma=10

AutoHide=0
HideAlbum=0
SideGlow=1
