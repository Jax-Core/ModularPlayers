[AdditionalOptions]
Meter=String
Text=#Style# options
MeterStyle=Set.String:S | Set.OptionCat:S

[Option11]
Meter=String
Text=Reduce album art to bar
MeterStyle=Set.String:S | Set.OptionName:S
[Divider1132s]
Meter=Shape
MeterStyle=Set.Div:S
Group=Card
[Option12]
Meter=String
Text=Side glow
MeterStyle=Set.String:S | Set.OptionName:S

; ---------------------------------------------------------------------------- ;
;                                   Function                                   ;
; ---------------------------------------------------------------------------- ;=

[Scale]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option01:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Value01]
Meter=String
Text=#Scale#
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