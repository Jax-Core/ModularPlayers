[Option1]
Meter=String
Text="Show shuffle Button"
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:02]
Meter=Shape
MeterStyle=Set.Div:S
[Option2]
Meter=String
Text="Show repeat Button"
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

[ShowShuffle]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option1:Y]-#Set.P#+(-20/2+8)*[Set.S])
[ShowRepeat]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option2:Y]-#Set.P#+(-20/2+8)*[Set.S])

; ---------------------------------------------------------------------------- ;
;                                    Anchor                                    ;
; ---------------------------------------------------------------------------- ;


[AnchorSuppli]
Meter=String
Container=ContentContainer
x=r
Y=R
