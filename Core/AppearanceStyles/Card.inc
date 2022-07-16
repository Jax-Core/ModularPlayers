

[Option11]
Meter=String
Text=Background color
MeterStyle=Set.String:S | Set.OptionName:S
[Divider1132s]
Meter=Shape
MeterStyle=Set.Div:S
Group=Card
[Option12]
Meter=String
Text=Font color
MeterStyle=Set.String:S | Set.OptionName:S

;================================================================================================================================================================================

[Scale]
Meter=Shape
MeterStyle=Set.Textbox:S
Type=Num|0.5|2
Y=([Option01:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value01]
Meter=String
Text=#Scale#
MeterStyle=Set.String:S | Set.Value:S

[Main]
Meter=Shape
MeterStyle=Set.ColorPacity:S
Y=([Option11:Y]-#Set.P#+(-30/2+8)*[Set.S])
Type=Num|1|255
[Value11]
Meter=String
Text=#MainOpacity#
MeterStyle=Set.String:S | Set.Pacity:S
[OppositeColor]
Meter=Shape
MeterStyle=Set.Color:S
Y=([Option12:Y]-#Set.P#+(-30/2+8)*[Set.S])
; ---------------------------------------------------------------------------- ;
;                                    Anchor                                    ;
; ---------------------------------------------------------------------------- ;


[AnchorSuppli]
Meter=String
Container=ContentContainer
x=r
Y=R