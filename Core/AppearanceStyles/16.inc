; ---------------------------------------------------------------------------- ;
;                                  MeterStyle                                  ;
; ---------------------------------------------------------------------------- ;
[Item.Shape:S]
X=(30*[Set.S])
Y=(35*[SEt.S])r
Shape=Rectangle 0,0,([ContentContainer:W]-#Set.P#),(50*[SEt.S]),(2*[Set.S]) | StrokeWidth 0 | Extend Fill
Fill=Fill Color #Set.Sec_Color#
Stroke=Stroke Color #Set.Ter_Color#
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Ter_Color#"][!SetOption #CURRENTSECTION# Stroke "Stroke Color #Set.Subtext_Color#,50"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Sec_Color#"][!SetOption #CURRENTSECTION# Stroke "Stroke Color #Set.Ter_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
DynamicVariables=1
Container=ContentContainer
[Item.StringIcon:S]
X=(50*[Set.S]/2)r
Y=(50*[Set.S]/2)r
StringAlign=leftCenter
FontFace=Segoe Fluent Icons
Container=ContentContainer
[Item.String:S]
X=(#Set.P#/2)R
Y=r
StringAlign=LeftCenter
Container=ContentContainer
[Item.Arrow.String:S]
X=([ContentContainer:W]-#Set.P#)
Y=r
StringAlign=RightCenter
Text=>
Container=ContentContainer

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[Item01.Shape]
Meter=Shape
Leftmouseupaction=[!WriteKeyValue Variables Cache.Wallpaper "" "#Sec.SaveLocation#"][!Refresh "#Skin.Name#\Main"]
MeterStyle=Item.Shape:S
[Item01.StringIcon]
Meter=String
Text=[\xe72c]
MeterStyle=Set.String:S | Item.StringIcon:S
[Item01.String]
Meter=String
Text=Click here to regenerate blur
MeterStyle=Set.String:S | Item.String:S
[Item01.Arrow.String]
Meter=String
MeterStyle=Set.String:S | Item.Arrow.String:S

[Divider132sdsd8]
Meter=Shape
X=(30*[Set.S])
MeterStyle=Set.Div:S
[Option11]
Meter=String
Text=Blur modulation (Brightness, Saturation, Hue)  
MeterStyle=Set.String:S | Set.OptionName:S
[Divider132sdasd8]
Meter=Shape
MeterStyle=Set.Div:S
[Option12]
Meter=String
Text=Blur sigma
MeterStyle=Set.String:S | Set.OptionName:S
[Divider192weewe03s8]
Meter=Shape
MeterStyle=Set.Div:S
[Option13]
Meter=String
Text=Blur radius
MeterStyle=Set.String:S | Set.OptionName:S
[Divider192we3s8]
Meter=Shape
MeterStyle=Set.Div:S
[Option14]
Meter=String
Text=Font color
MeterStyle=Set.String:S | Set.OptionName:S

; ---------------------------------------------------------------------------- ;
;                                   Function                                   ;
; ---------------------------------------------------------------------------- ;=

[Scale]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Num|0.5|2
Y=([Option01:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value01]
Meter=String
Text=#Scale#
MeterStyle=Set.String:S | Set.Value:S

[BlurModulate]
Meter=Shape
MeterStyle=Set.TextBox:S
Y=([Option11:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value11]
Meter=String
Text=#BlurModulate#
MeterStyle=Set.String:S | Set.Value:S

[BlurSigma]
Meter=Shape
MeterStyle=Set.TextBox:S
Y=([Option12:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value12]
Meter=String
Text=#BlurSigma#
MeterStyle=Set.String:S | Set.Value:S

[BlurRadius]
Meter=Shape
MeterStyle=Set.TextBox:S
Y=([Option13:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value13]
Meter=String
Text=#BlurRadius#
MeterStyle=Set.String:S | Set.Value:S

[FontColor]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option14:Y]-#Set.P#+(-30/2+8)*[Set.S])

; ---------------------------------------------------------------------------- ;
;                                    Anchor                                    ;
; ---------------------------------------------------------------------------- ;


[AnchorSuppli]
Meter=String
Container=ContentContainer
x=r
Y=R