[AdditionalOptions]
Meter=String
Text=#Style# options
MeterStyle=Set.String:S | Set.OptionCat:S

[Option11]
Meter=String
Text="Width"
MeterStyle=Set.String:S | Set.OptionName:S
; [Set.Div:01]
; Meter=Shape
; MeterStyle=Set.Div:S
; [Option12]
; Meter=String
; Text="Rounding radius"
; MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:02]
Meter=Shape
MeterStyle=Set.Div:S
[Option13]
Meter=String
Text="Font face"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:03]
Meter=Shape
MeterStyle=Set.Div:S
[Option14]
Meter=String
Text="Border size"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:04]
Meter=Shape
MeterStyle=Set.Div:S
[Option15]
Meter=String
Text="Bar dot size (doesn't affect the hitbox)"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:05]
Meter=Shape
MeterStyle=Set.Div:S
[Option16]
Meter=String
Text="Bar cap"
MeterStyle=Set.String:S | Set.OptionName:S

[ColorTitle]
Meter=String
Text="Color settings"
MeterStyle=Set.String:S | Set.OptionCat:S
[Option21]
Meter=String
Text="Background color"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:11]
Meter=Shape
MeterStyle=Set.Div:S
[Option22]
Meter=String
Text="Border color"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:12]
Meter=Shape
MeterStyle=Set.Div:S
[Option23]
Meter=String
Text="Top tier font color"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:13]
Meter=Shape
MeterStyle=Set.Div:S
[Option24]
Meter=String
Text="Second tier font color"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:14]
Meter=Shape
MeterStyle=Set.Div:S
[Option25]
Meter=String
Text="Accent color"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:15]
Meter=Shape
MeterStyle=Set.Div:S

; ---------------------------------------------------------------------------- ;
;                                   Function                                   ;
; ---------------------------------------------------------------------------- ;

[Scale]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Num|0.5|2
Y=([Option01:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value01]
Meter=String
Text=#Scale#
MeterStyle=Set.String:S | Set.Value:S


[W]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Num|200|600
Y=([Option11:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value11]
Meter=String
Text="#W#"
MeterStyle=Set.String:S | Set.Value:S
; [R]
; Meter=Shape
; MeterStyle=Set.Textbox:S
; Type=Num|0|20
; Y=([Option12:Y]-#Set.P#+(-30/2+8)*[Set.S])
; [Value12]
; Meter=String
; Text="#R# px"
; MeterStyle=Set.String:S | Set.Value:S
[Fontface]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Txt
Y=([Option13:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value13]
Meter=String
Text="#Fontface#"
MeterStyle=Set.String:S | Set.Value:S
[Stroke]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Num|0|4
Y=([Option14:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value14]
Meter=String
Text="#Stroke#"
MeterStyle=Set.String:S | Set.Value:S
[DotSize]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Num|0|30
Y=([Option15:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value15]
Meter=String
Text="#DotSize#"
MeterStyle=Set.String:S | Set.Value:S
[Cap:]
Meter=Shape
0Act=[!WriteKeyValue Variables Cap "Flat" "#Sec.SaveLocation#"]
1Act=[!WriteKeyValue Variables Cap "Round" "#Sec.SaveLocation#"]
2Act=[!WriteKeyValue Variables Cap "Triangle" "#Sec.SaveLocation#"]
MeterStyle=Set.Pick3:S
Shape2=Rectangle (100*[Set.S]*([&Func:returnBool('Cap', 'Round')]+[&Func:returnBool('Cap', 'Triangle')]*2)),0,(300/3*[Set.S]),(30*[Set.S]),(7*[Set.S]) | Fill Color #Set.Text_Color# | StrokeWidth 0
Y=([Option16:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Cap:0]
Meter=String
Text=Flat
FontColor=[&Func:returnBool('Cap', 'Flat', '#Set.Pri_color#', '#Set.Text_Color#')]
MeterStyle=Set.String:S | Set.PickOption3_0:S
[Cap:1]
Meter=String
Text=Round
FontColor=[&Func:returnBool('Cap', 'Round', '#Set.Pri_color#', '#Set.Text_Color#')]
MeterStyle=Set.String:S | Set.PickOption3_1:S
[Cap:2]
Meter=String
Text=Triangle
FontColor=[&Func:returnBool('Cap', 'Triangle', '#Set.Pri_color#', '#Set.Text_Color#')]
MeterStyle=Set.String:S | Set.PickOption3_2:S

[Primary]
Meter=Shape
MeterStyle=Set.ColorPacity:S
Y=([Option21:Y]-#Set.P#+(-30/2+8)*[Set.S])
Type=Num|1|255
[Value21]
Meter=String
Text=#PrimaryOpacity#
MeterStyle=Set.String:S | Set.Pacity:S
[Secondary]
Meter=Shape
MeterStyle=Set.ColorPacity:S
Y=([Option22:Y]-#Set.P#+(-30/2+8)*[Set.S])
Type=Num|1|255
[Value21]
Meter=String
Text=#SecondaryOpacity#
MeterStyle=Set.String:S | Set.Pacity:S
[FontColor]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option23:Y]-#Set.P#+(-30/2+8)*[Set.S])
[FontColor2]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option24:Y]-#Set.P#+(-30/2+8)*[Set.S])
[AccentColor]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option25:Y]-#Set.P#+(-30/2+8)*[Set.S])
; ---------------------------------------------------------------------------- ;
;                                    Anchor                                    ;
; ---------------------------------------------------------------------------- ;


[AnchorSuppli]
Meter=String
Container=ContentContainer
x=r
Y=R