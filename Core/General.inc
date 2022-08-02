[Variables]
Sec.SaveLocation=#SKINSPATH##SKin.Name#\@Resources\Vars.inc


; ---------------------------------------------------------------------------- ;
;                                    Styles                                    ;
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
[Item.Button.Shape:S]
X=([ContentContainer:W]-#Set.P#-30*[SEt.S])
Y=(-15*[Set.S])r
Shape=Rectangle 0,0,(30*[Set.S]),(30*[Set.S]),(5*[Set.S]) | StrokeWidth 0 | Extend Stroke
Stroke=Fill Color #Set.Positive_color#,100
MouseOverAction=[!SetOption #CURRENTSECTION# Stroke "Fill Color #Set.Positive_color#,200"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Stroke "Fill Color #Set.Positive_color#,100"][!UpdateMeter #CURRENTSECTION#][!Redraw]
DynamicVariables=1
Container=ContentContainer
[Item.Button.StringIcon:S]
X=(30*[Set.S]/2)r
Y=(30*[Set.S]/2)r
StringAlign=CenterCEnter
Text=[\xe5ce]
FontFace=Material Icons Round
Container=ContentContainer

[Box]
X=(20*[Set.S])R
Y=r
Shape=Rectangle  0,0,(([ContentContainer:W]-120*[Set.S])/5),(([ContentContainer:W]-120*[Set.S])/5),#set.R# | StrokeWidth 0 | Extend Fill
Fill=Fill Color #Set.Text_Color#,10
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Text_Color#,150"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Text_Color#,10"][!UpdateMeter #CURRENTSECTION#][!Redraw]
DynamicVariables=1
Container=ContentContainer

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[Clock]
Meter=String
Text=Player style // #Style#
MeterStyle=Set.String:S | Set.OptionCat:S

[Item1.Shape]
Meter=Shape
MeterStyle=Item.Shape:S
[Item1.StringIcon]
Meter=String
Text=[\xe814]
MeterStyle=Set.String:S | Item.StringIcon:S
[Item1.String]
Meter=String
Text=For all styles with an icon on the top left, MagickMeter is required. 
MeterStyle=Set.String:S | Item.String:S
[Item1.Button]
Meter=Shape
MeterStyle=Item.Button.Shape:S
[Item1.Button.StringIcon]
Meter=String
Text=[\xe89e]
LeftMouseUpAction=["https://jaxcore.gitbook.io/core/getting-started/additional-requisites#imagemagick"]
MeterStyle=Set.String:S | Item.Button.StringIcon:S

[Box1]
Meter=Shape
X=(30*[Set.S])
Y=(30*[Set.S])R
MeterStyle=Box
[Box2]
Meter=Shape
MeterStyle=Box
[Box3]
Meter=Shape
MeterStyle=Box
[Box4]
Meter=Shape
MeterStyle=Box
[Box5]
Meter=Shape
MeterStyle=Box
[Box6]
Meter=Shape
X=(30*[Set.S])
Y=(20*[Set.S])R
MeterStyle=Box
[Box7]
Meter=Shape
MeterStyle=Box
[Box8]
Meter=Shape
MeterStyle=Box
[Box9]
Meter=Shape
MeterStyle=Box
[Box10]
Meter=Shape
MeterStyle=Box
[Box11]
Meter=Shape
X=(30*[Set.S])
Y=(30*[Set.S])R
MeterStyle=Box


[Side]
Meter=Image
Imagename=#SKINSPATH#ModularPlayers\@Resources\Images\Preview\#CURRENTSECTION#.png
X=([Box1:X]-[ContentContainer:X])
Y=([Box1:Y]-[ContentContainer:Y])
W=(([ContentContainer:W]-120*[Set.S])/5)
H=(([ContentContainer:W]-120*[Set.S])/5)
Solidcolor=0,0,0,1
Leftmouseupaction=[!WriteKeyValue Variables Style #CURRENTSECTION# "#Sec.SaveLocation#"][!Refresh][!UpdateMeasure Auto_Refresh:M]
DynamicVariables=1
Container=ContentContainer
ToolTipTitle=#CURRENTSECTION#
ToolTipText=Click to switch to this layout

[Blur]
Meter=Image
X=([Box1:W]+20*[Set.S])r
Y=r
Leftmouseupaction=[!CommandMeasure Func "PopupImageMagick('#CURRENTSECTION#', 'BangToRun')"]
BangToRun=[!WriteKeyValue Variables Style #CURRENTSECTION# "#Sec.SaveLocation#"][!Refresh][!UpdateMeasure Auto_Refresh:M]
MeterStyle=Side

[MMI1]
Meter=Image
ImageName=#@#Icons\Settings\MagickMeterIcon.png
X=r
y=r
W=(24*[Set.S])
H=(24*[Set.S])
Padding=10,10,10,10
DynamicVariables=1
LeftMouseUpAction=[!ActivateConfig "#Skin.Name#\@Start"]
Container=ContentContainer
ToolTipTitle=MagickMeter is required for this layout!
ToolTipText=Click on the guide above to learn how to install it.

[Simple]
Meter=Image
X=([Box1:W]+20*[Set.S])r
Y=r
MeterStyle=Side

[Card]
Meter=Image
X=([Box1:W]+20*[Set.S])r
Y=r
Leftmouseupaction=[!CommandMeasure Func "PopupImageMagick('#CURRENTSECTION#', 'BangToRun')"]
BangToRun=[!WriteKeyValue Variables Style #CURRENTSECTION# "#Sec.SaveLocation#"][!Refresh][!UpdateMeasure Auto_Refresh:M]
MeterStyle=Side

[MMI2]
Meter=Image
MeterStyle=MMI1

[Modern]
Meter=Image
X=([Box1:W]+20*[Set.S])r
Y=r
MeterStyle=Side

[Neumorphism]
Meter=Image
X=([Box6:X]-[ContentContainer:X])
Y=([Box6:Y]-[ContentContainer:Y])
MeterStyle=Side

[Center]
Meter=Image
X=([Box1:W]+20*[Set.S])r
Y=r
MeterStyle=Side

[BigCirc]
Meter=Image
X=([Box1:W]+20*[Set.S])r
Y=r
Leftmouseupaction=[!CommandMeasure Func "PopupImageMagick('#CURRENTSECTION#', 'BangToRun')"]
BangToRun=[!WriteKeyValue Variables Style #CURRENTSECTION# "#Sec.SaveLocation#"][!Refresh][!UpdateMeasure Auto_Refresh:M]
MeterStyle=Side

[MMI8]
Meter=Image
MeterStyle=MMI1

[MIUI]
Meter=Image
X=([Box1:W]+20*[Set.S])r
Y=r
MeterStyle=Side

[Win11]
Meter=Image
X=([Box1:W]+20*[Set.S])r
Y=r
MeterStyle=Side

[16]
Meter=Image
X=([Box11:X]-[ContentContainer:X])
Y=([Box11:Y]-[ContentContainer:Y])
Leftmouseupaction=[!CommandMeasure Func "PopupImageMagick('#CURRENTSECTION#', 'BangToRun')"]
BangToRun=[!WriteKeyValue Variables Style #CURRENTSECTION# "#Sec.SaveLocation#"][!Refresh][!UpdateMeasure Auto_Refresh:M]
MeterStyle=Side

[MMI11]
Meter=Image
MeterStyle=MMI1

; ---------------------------------------------------------------------------- ;
;                                     Input                                    ;
; ---------------------------------------------------------------------------- ;

[Header2]
Meter=String
Text=Customization
Y=([16:YH])
MeterStyle=Set.String:S | Set.OptionCat:S

[Item2.Shape]
Meter=Shape
LeftMouseUpAction=[!WriteKeyvalue Variables "Skin.Set_Page" "Appearance" "#@#SecVar.inc"][!Refresh]
MeterStyle=Item.Shape:S
[Item2.StringIcon]
Meter=String
Text=[\xe790]
MeterStyle=Set.String:S | Item.StringIcon:S
[Item2.String]
Meter=String
Text=Customize player in style options
MeterStyle=Set.String:S | Item.String:S