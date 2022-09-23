

[Option11]
Meter=String
Text=Accent color 1
MeterStyle=Set.String:S | Set.OptionName:S
[Divider:1]
Meter=Shape
MeterStyle=Set.Div:S
Group=Card
[Option12]
Meter=String
Text=Accent color 2
MeterStyle=Set.String:S | Set.OptionName:S
[Divider113]
Meter=Shape
MeterStyle=Set.Div:S
Group=Card
[Option13]
Meter=String
Text=Background color
MeterStyle=Set.String:S | Set.OptionName:S
[Divider1132s]
Meter=Shape
MeterStyle=Set.Div:S
Group=Card
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

[Accent.1]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option11:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Accent.2]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option12:Y]-#Set.P#+(-30/2+8)*[Set.S])
[MainColor]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option13:Y]-#Set.P#+(-30/2+8)*[Set.S])
[OppositeColor]
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