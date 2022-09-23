
[Option10]
Meter=String
Text=Album art / bar height
MeterStyle=Set.String:S | Set.OptionName:S
[Divider1]
Meter=Shape
MeterStyle=Set.Div:S

[Option11]
Meter=String
Text=Reduce album art to bar
MeterStyle=Set.String:S | Set.OptionName:S
[Divider1132s]
Meter=Shape
MeterStyle=Set.Div:S

[Option12]
Meter=String
Text=Side glow
MeterStyle=Set.String:S | Set.OptionName:S
[Divider3]
Meter=Shape
MeterStyle=Set.Div:S

[Option13]
Meter=String
Text=Bar width
Fontcolor=#Set.Text_Color#,(105+150*#HideAlbum#)
MeterStyle=Set.String:S | Set.OptionName:S
[Divider4]
Meter=Shape
MeterStyle=Set.Div:S

[Option14]
Meter=String
Text=Bar rounding radius
Fontcolor=#Set.Text_Color#,(105+150*#HideAlbum#)
MeterStyle=Set.String:S | Set.OptionName:S
[Divider5]
Meter=Shape
MeterStyle=Set.Div:S

[Option15]
Meter=String
Text=Automatically scroll text
MeterStyle=Set.String:S | Set.OptionName:S
[Divider6]
Meter=Shape
MeterStyle=Set.Div:S

[Option16]
Meter=String
Text=Text scrolling update rate
MeterStyle=Set.String:S | Set.OptionName:S
[Divider7]
Meter=Shape
MeterStyle=Set.Div:S

[Option17]
Meter=String
Text=Text scrolling multiplier
MeterStyle=Set.String:S | Set.OptionName:S
[Divider8]
Meter=Shape
MeterStyle=Set.Div:S

[Option18]
Meter=String
Text=Main color
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


[H]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Num|170|300
Y=([Option10:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value10]
Meter=String
Text=#H#
MeterStyle=Set.String:S | Set.Value:S
[HideAlbum]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option11:Y]-#Set.P#+(-20/2+8)*[Set.S])
Group=Side
[SideGlow]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option12:Y]-#Set.P#+(-20/2+8)*[Set.S])
Group=Side
[BarW]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Num|0|20
Y=([Option13:Y]-#Set.P#+(-30/2+8)*[Set.S])
Hidden=(1-#HideAlbum#)
[Value13]
Meter=String
Text=#BarW#
MeterStyle=Set.String:S | Set.Value:S
Hidden=(1-#HideAlbum#)
[BarCorner]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Num|0|20
Y=([Option14:Y]-#Set.P#+(-30/2+8)*[Set.S])
Hidden=(1-#HideAlbum#)
[Value14]
Meter=String
Text=#BarCorner#
MeterStyle=Set.String:S | Set.Value:S
Hidden=(1-#HideAlbum#)
[AutoScroll]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option15:Y]-#Set.P#+(-20/2+8)*[Set.S])
Group=Side
[UpdateRate]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Num|5|100
Y=([Option16:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value16]
Meter=String
Text=#UpdateRate#
MeterStyle=Set.String:S | Set.Value:S
[RollSpeedMultiplier]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Num|0.1|3
Y=([Option17:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value17]
Meter=String
Text=#RollSpeedMultiplier#x
MeterStyle=Set.String:S | Set.Value:S
[MainColor]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option18:Y]-#Set.P#+(-30/2+8)*[Set.S])
; ---------------------------------------------------------------------------- ;
;                                    Anchor                                    ;
; ---------------------------------------------------------------------------- ;


[AnchorSuppli]
Meter=String
Container=ContentContainer
x=r
Y=R