[Section2.Icon]
MeterStyle=Set.String:S | Set.Icon:S | Section2.Icon:#AutoHide#
[Section2.Icon:0]
FontColor=#Set.Accent_Color#
InlineSetting=Shadow | 0 | 0 | 2 | #Set.Accent_Color#
[Section2.Icon:1]
FontColor=#Set.Positive_Color#
InlineSetting=Shadow | 0 | 0 | 2 | #Set.Positive_Color#

[Section2.Text]
MeterStyle=Set.String:S | Section2.Text:#AutoHide#
[Section2.Text:0]
Text=Player will always be visible#CRLF#Player will display nothing when no media is playing
[Section2.Text:1]
Text=Player will automatically hide itself#CRLF#When there are no media playing, the player hides itself

[FetchImage]
Meter=Shape
Shape=
Shape2=

[AutoHide]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([FetchImage:Y]-[ContentContainer:Y])
X=([ContentContainer:W]-#Set.P#-60*[Set.S])
