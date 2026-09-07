$ErrorActionPreference = "Stop"
$root = Split-Path -Parent $MyInvocation.MyCommand.Path
Set-Location $root

$tests = @(
    @{ N=401; Label="4.01)Engine Oil Temperature"; Spec="60+/-2 C"; Caption="Engine Oil Temperature";
       EditId="IDC_EDIT_OILTEMP"; Dummy="61"; VType="dbl"; Min=58; Max=62; Find="";
       Msg="Oil Temperature out of range. Continue?";
       FcEdt="m_edtoiltemp"; RcEdt="m_edt_SmfdRc_EnOilTemp"; Meas="m_stroiltemp"; Stat="m_strStatusoiltemp" },
    @{ N=402; Label="4.02)Engine Oil Pressure"; Spec="40+/-3 psi"; Caption="Engine Oil Pressure";
       EditId="IDC_EDIT_OILPRES"; Dummy="41"; VType="dbl"; Min=37; Max=43; Find="";
       Msg="Oil Pressure out of range. Continue?";
       FcEdt="m_edtoilpressure"; RcEdt="m_edt_SmfdRc_EnOilPress"; Meas="m_stroilpressure"; Stat="m_strStatusoilpressure" },
    @{ N=403; Label="4.03)Engine Torque"; Spec="1740+/-4 ft-lb"; Caption="Engine Torque";
       EditId="IDC_EDIT_TORQUE"; Dummy="1742"; VType="dbl"; Min=1736; Max=1744; Find="";
       Msg="Torque invalid. Continue?";
       FcEdt="m_edttorque"; RcEdt="m_edt_SmfdRc_EnTor"; Meas="m_strtorque"; Stat="m_strStatustorque" },
    @{ N=404; Label="4.04)Rudder Trim Position"; Spec="Nose at centre white line"; Caption="Rudder Trim Position";
       EditId="IDC_EDIT_RUDER"; Dummy="Nose at center white line"; VType="find"; Min=0; Max=0; Find="center";
       Msg="Rudder position incorrect. Continue?";
       FcEdt="m_edtrudder"; RcEdt="m_edt_SmfdRc_RudTrimPos"; Meas="m_strrudder"; Stat="m_strStatusrudder" },
    @{ N=405; Label="4.05)Elevator Trim Position"; Spec="Nose at green line and -1.2 deg"; Caption="Elevator Trim Position";
       EditId="IDC_EDIT_ELEVATOR"; Dummy="-1.2 deg"; VType="find"; Min=0; Max=0; Find="deg";
       Msg="Elevator value incorrect. Continue?";
       FcEdt="m_edtelevator"; RcEdt="m_edt_SmfdRc_ElevTrimPos"; Meas="m_strelevator"; Stat="m_strStatuselevator" },
    @{ N=406; Label="4.06)Aileron Trim Position"; Spec="Wing at green line"; Caption="Aileron Trim Position";
       EditId="IDC_EDIT_AILERON"; Dummy="wing at green line"; VType="find"; Min=0; Max=0; Find="green";
       Msg="Aileron not in green range. Continue?";
       FcEdt="m_edtaileron"; RcEdt="m_edt_SmfdRc_AilTrimPos"; Meas="m_straileron"; Stat="m_strStatusaileron" },
    @{ N=407; Label="4.07)Flap Position at 3V"; Spec="Flaps 20 in Green"; Caption="Flap Position at 3V";
       EditId="IDC_EDIT_FLAT3V"; Dummy="Flaps 20 in green"; VType="find"; Min=0; Max=0; Find="green";
       Msg="Flap 3V incorrect. Continue?";
       FcEdt="m_edtflap3V"; RcEdt="m_edt_SmfdRc_FlPos3V"; Meas="m_strflap3v"; Stat="m_strStatusflap3v" },
    @{ N=408; Label="4.08)Flap Position at 4.31 V"; Spec="Flaps 30 in Yellow"; Caption="Flap Position at 4.31 V";
       EditId="IDC_EDIT_FLAP4V"; Dummy="Flaps 30 in yellow"; VType="find"; Min=0; Max=0; Find="yellow";
       Msg="Flap 4V incorrect. Continue?";
       FcEdt="m_edtflap4v"; RcEdt="m_edt_SmfdRc_FlapPos4V"; Meas="m_strflap4v"; Stat="m_strStatusflap4v" },
    @{ N=409; Label="4.09)Generator Voltage"; Spec="28+/-1 V"; Caption="Generator Voltage";
       EditId="IDC_EDIT_GENERAL_V"; Dummy="28"; VType="dbl"; Min=27; Max=29; Find="";
       Msg="Generator voltage out of range. Continue?";
       FcEdt="m_edtgenvol"; RcEdt="m_edt_SmfdRc_GenVol"; Meas="m_strgenvolt"; Stat="m_strStatusgenvolt" },
    @{ N=410; Label="4.10)Battery Voltage"; Spec="28+/-1 V"; Caption="Battery Voltage";
       EditId="IDC_EDIT_BATTERY_VOLT"; Dummy="28"; VType="dbl"; Min=27; Max=29; Find="";
       Msg="Battery voltage out of range. Continue?";
       FcEdt="m_edtbattvol"; RcEdt="m_edt_SmfdRc_Battvol"; Meas="m_strbatvolt"; Stat="m_strStatusbatvolt" },
    @{ N=411; Label="4.11)Current Load"; Spec="200+/-10 A"; Caption="Current Load";
       EditId="IDC_EDIT_CURR"; Dummy="202"; VType="dbl"; Min=190; Max=210; Find="";
       Msg="Current load invalid. Continue?";
       FcEdt="m_edtcurvol"; RcEdt="m_edt_SmfdRc_CurrLoad"; Meas="m_strcurload"; Stat="m_strStatuscurload" },
    @{ N=412; Label="4.12) Hydraulics Pressure Main"; Spec="2930+/-20 psi"; Caption="Hydraulics Pressure Main";
       EditId="IDC_EDIT_HYDPRESMAIN"; Dummy="2940"; VType="int"; Min=2910; Max=2950; Find="";
       Msg="Hydraulic Main Pressure not in range, Continue?";
       FcEdt="m_edt_hydpresmain"; RcEdt="m_edt_SmfdRc_HyPrMain"; Meas="m_strHydPresMain"; Stat="m_strStatusHydPresMain" },
    @{ N=413; Label="4.13) Hydraulics Pressure Emergency"; Spec="3330+/-20 psi"; Caption="Hydraulics Pressure Emergency";
       EditId="IDC_EDIT_HYDPRESEMER"; Dummy="3340"; VType="int"; Min=3310; Max=3350; Find="";
       Msg="Hydraulic Emergency Pressure not OK, Continue?";
       FcEdt="m_edt_hydpresemer"; RcEdt="m_edt_SmfdRc_HyPrEm"; Meas="m_strHydPresEmer"; Stat="m_strStatusHydPresEmer" },
    @{ N=414; Label="4.14) Emergency Brake (Accumulator Pressure)"; Spec="1300+/-15 psi"; Caption="Emergency Brake Accumulator Pressure";
       EditId="IDC_EDIT_ACCUMPRES"; Dummy="1307"; VType="int"; Min=1285; Max=1315; Find="";
       Msg="Emergency Brake Pressure not OK, Continue?";
       FcEdt="m_edt_emerbrake"; RcEdt="m_edt_SmfdRc_EmBr"; Meas="m_strEmerBrake"; Stat="m_strStatusEmerBrake" },
    @{ N=415; Label="4.15) LH Brake Pressure"; Spec="1200+/-15 psi"; Caption="LH Brake Pressure";
       EditId="IDC_EDIT_LHBRAKE"; Dummy="1205"; VType="int"; Min=1185; Max=1215; Find="";
       Msg="LH Brake Pressure not OK, Continue?";
       FcEdt="m_edt_Lhbrake"; RcEdt="m_edt_SmfdRc_LHBr"; Meas="m_strLhBrake"; Stat="m_strStatusLhBrake" },
    @{ N=416; Label="4.16) RH Brake Pressure"; Spec="1200+/-15 psi"; Caption="RH Brake Pressure";
       EditId="IDC_EDIT_RHBRAKE"; Dummy="1205"; VType="int"; Min=1185; Max=1215; Find="";
       Msg="RH Brake Pressure not OK, Continue?";
       FcEdt="m_edt_rhbrake"; RcEdt="m_edt_SmfdRc_RhBr"; Meas="m_strRhBrake"; Stat="m_strStatusRhBrake" },
    @{ N=417; Label="4.17) Engine Speed"; Spec="79+/-2 % rpm"; Caption="Engine Speed";
       EditId="IDC_EDIT_ENGSPD"; Dummy="80"; VType="int"; Min=77; Max=81; Find="";
       Msg="Engine Speed not OK, Continue?";
       FcEdt="m_edt_enginespd"; RcEdt="m_edt_SmfdRc_EnSpeed"; Meas="m_strEngineSpd"; Stat="m_strStatusEngineSpd" },
    @{ N=418; Label="4.18) Fuel Tank LH"; Spec="168+/-5 lb"; Caption="Fuel Tank LH";
       EditId="IDC_EDIT_LHFUEL"; Dummy="170"; VType="int"; Min=163; Max=173; Find="";
       Msg="LH Fuel not OK, Continue?";
       FcEdt="m_edt_fuelLh"; RcEdt="m_edt_SmfdRc_FuelTankLH"; Meas="m_strFuelLh"; Stat="m_strStatusFuelLh" },
    @{ N=419; Label="4.19) Fuel Tank RH"; Spec="161+/-5 lb"; Caption="Fuel Tank RH";
       EditId="IDC_EDIT_RHFUEL"; Dummy="162"; VType="int"; Min=156; Max=166; Find="";
       Msg="RH Fuel not OK, Continue?";
       FcEdt="m_edt_fuelRh"; RcEdt="m_edt_SmfdRc_FuelTankRH"; Meas="m_strFuelRh"; Stat="m_strStatusFuelRh" },
    @{ N=420; Label="4.20) Collector Tank"; Spec="183+/-5 lb"; Caption="Collector Tank";
       EditId="IDC_EDIT_COLLECTORANK"; Dummy="185"; VType="int"; Min=178; Max=188; Find="";
       Msg="Collector Tank Fuel not OK, Continue?";
       FcEdt="m_edt_collectortank"; RcEdt="m_edt_SmfdRc_CoTank"; Meas="m_strCollectorTank"; Stat="m_strStatusCollectorTank" }
)

function Get-OkBody($t, $edt) {
    if ($t.VType -eq "dbl") {
        return @"
    double val = _tstof($edt);
    if (val >= $($t.Min) && val <= $($t.Max))
    {
        $($t.Meas) = $edt;
        $($t.Stat) = "OK";
    }
    else
    {
        g_strMsgStr = "$($t.Msg)";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        $($t.Meas) = $edt;
        $($t.Stat) = "NOT OK";
    }
"@
    }
    elseif ($t.VType -eq "int") {
        return @"
    int val = atoi($edt);
    if (val >= $($t.Min) && val <= $($t.Max))
    {
        $($t.Meas) = $edt;
        $($t.Stat) = "OK";
    }
    else
    {
        g_strMsgStr.Format("$($t.Msg)");
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        $($t.Meas) = $edt;
        $($t.Stat) = "NOT OK";
    }
"@
    }
    else {
        return @"
    if ($edt.Find("$($t.Find)") != -1)
    {
        $($t.Meas) = $edt;
        $($t.Stat) = "OK";
    }
    else
    {
        g_strMsgStr = "$($t.Msg)";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        $($t.Meas) = $edt;
        $($t.Stat) = "NOT OK";
    }
"@
    }
}

function Write-DialogFiles($t, $cockpit) {
    $n = $t.N
    $suffix = "{0:D3}" -f ($n - 400 + 1)
    if ($cockpit -eq "FC") {
        $class = "CDialog_Smfd_Analog_$n"
        $file = "Dialog_Smfd_Analog_$n"
        $idd = "IDD_DIALOG_SMFD_ANALOG_$n"
        $edt = $t.FcEdt
        $base = "CDialogEx"
        $btnId = "IDC_BUTTON_SMFD_ANALOG"
        $btnFn = "OnBnClickedButtonSmfdAnalog"
        $capPrefix = "SMFD FC Analog Checks"
        $procCockpit = "SMFD FC"
    } else {
        $class = "CDialog_Smfd_Analog_RC_$n"
        $file = "Dialog_Smfd_Analog_RC_$n"
        $idd = "IDD_DIALOG_SMFD_ANALOG_RC_$n"
        $edt = $t.RcEdt
        $base = "CDialogEx"
        $btnId = "IDC_BUTTON_SMFD_ANALOG_RC"
        $btnFn = "OnBnClickedButtonSmfdAnalogRc"
        $capPrefix = "SMFD RC Analog Checks"
        $procCockpit = "SMFD RC"
    }

    $h = @"
#pragma once
#include "afxwin.h"
#include "resource.h"

class $class : public $base
{
	DECLARE_DYNAMIC($class)

public:
	$class(CWnd* pParent = NULL);
	virtual ~$class();

	enum { IDD = $idd };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	DECLARE_MESSAGE_MAP()

public:
	CString $edt;
	CString $($t.Meas);
	CString $($t.Stat);
	afx_msg void $btnFn();
	afx_msg void OnBnClickedOk();
};
"@
    Set-Content -Path (Join-Path $root "$file.h") -Value $h -Encoding ASCII

    $okBody = Get-OkBody $t $edt
    $cpp = @"
#include "stdafx.h"
#include "$file.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

IMPLEMENT_DYNAMIC($class, $base)

$class::$class(CWnd* pParent /*=NULL*/)
	: $base($class::IDD, pParent)
	, $edt(_T(""))
{
}

$class::~$class()
{
}

void $class::DoDataExchange(CDataExchange* pDX)
{
	$base::DoDataExchange(pDX);
	DDX_Text(pDX, $($t.EditId), $edt);
}

BEGIN_MESSAGE_MAP($class, $base)
	ON_BN_CLICKED(IDOK, &$class::OnBnClickedOk)
	ON_BN_CLICKED($btnId, &$class::$btnFn)
END_MESSAGE_MAP()

void $class::$btnFn()
{
	UpdateData(TRUE);
	$edt = "$($t.Dummy)";
	UpdateData(FALSE);
}

void $class::OnBnClickedOk()
{
	UpdateData(TRUE);
	CMessageBox_Dlg msgdlg;

$okBody
	UpdateData(FALSE);
	$base::OnOK();
}
"@
    Set-Content -Path (Join-Path $root "$file.cpp") -Value $cpp -Encoding ASCII

    $testNo = "4.{0:D2}" -f ($n - 400)
    $spec = $t.Spec.Replace("+/-", ([string][char]0x00B1))
    $rcDlg = @"
$idd DIALOGEX 0, 0, 415, 140
STYLE DS_SETFONT | DS_MODALFRAME | WS_POPUP | WS_CAPTION | WS_SYSMENU
CAPTION "$capPrefix(Test No. $testNo)"
FONT 11, "Arial", 400, 0, 0x0
BEGIN
    DEFPUSHBUTTON   "Continue",IDOK,226,110,50,14
    LTEXT           "Test Procedure :",IDC_STATIC,15,13,70,8
    LTEXT           "1) Click on Test button for performing analog input check on $procCockpit.",IDC_STATIC,33,29,320,8
    LTEXT           "$($t.Label)",IDC_STATIC,40,56,190,16
    EDITTEXT        $($t.EditId),235,54,59,14,ES_AUTOHSCROLL
    LTEXT           "$spec",IDC_STATIC,312,50,70,20
    GROUPBOX        "Expected",IDC_STATIC,306,38,80,36
    PUSHBUTTON      "Test",$btnId,133,110,47,14
    LTEXT           "2) Click on continue button to proceed for the next Test.",IDC_STATIC,37,90,220,8
END

"@
    return @{ File=$file; Class=$class; Idd=$idd; Rc=$rcDlg; N=$n; Cockpit=$cockpit; Meas=$t.Meas; Stat=$t.Stat }
}

$generated = @()
foreach ($t in $tests) {
    $generated += Write-DialogFiles $t "FC"
    $generated += Write-DialogFiles $t "RC"
}

# aggregator header
$inc = @("#pragma once")
foreach ($g in $generated) { $inc += "#include `"$($g.File).h`"" }
Set-Content -Path (Join-Path $root "Dialog_Smfd_Analog_All.h") -Value ($inc -join "`r`n") -Encoding ASCII

# resource.h (UTF-16)
$resPath = Join-Path $root "resource.h"
$res = Get-Content $resPath -Encoding Unicode -Raw
$idBlock = ""
$idVal = 674
foreach ($g in $generated) {
    $idBlock += ("#define {0,-35} {1}`r`n" -f $g.Idd, $idVal)
    $idVal++
}
$marker = "// Next default values for new objects"
if ($res -notmatch "IDD_DIALOG_SMFD_ANALOG_401") {
    $res = $res.Replace($marker, $idBlock + "`r`n" + $marker)
}
$res = $res.Replace("#define _APS_NEXT_RESOURCE_VALUE        674", "#define _APS_NEXT_RESOURCE_VALUE        $idVal")
Set-Content -Path $resPath -Value $res -Encoding Unicode -NoNewline

# SIPU_SDU_GndRig.rc
$rcPath = Join-Path $root "SIPU_SDU_GndRig.rc"
$rc = Get-Content $rcPath -Raw -Encoding Default
$rcInsert = ($generated | ForEach-Object { $_.Rc }) -join "`r`n"
$anchor = "IDD_DIALOG_SMFD_DISCRETE_RC DIALOGEX 0, 0, 465, 288"
if ($rc -notmatch "IDD_DIALOG_SMFD_ANALOG_401") {
    $rc = $rc.Replace($anchor, $rcInsert + "`r`n" + $anchor)
}
$desInsert = ""
foreach ($g in $generated) {
    $desInsert += @"
    $($g.Idd), DIALOG
    BEGIN
        LEFTMARGIN, 7
        RIGHTMARGIN, 408
        TOPMARGIN, 7
        BOTTOMMARGIN, 133
    END

"@
}
$desAnchor = "    IDD_DIALOG_SMFD_DISCRETE_RC, DIALOG"
if ($rc -notmatch "IDD_DIALOG_SMFD_ANALOG_401, DIALOG") {
    $rc = $rc.Replace($desAnchor, $desInsert + $desAnchor)
}
Set-Content -Path $rcPath -Value $rc -Encoding Default -NoNewline

# ATI_UT.vcxproj
$projPath = Join-Path $root "ATI_UT.vcxproj"
$proj = Get-Content $projPath -Raw
$hItems = ""
$cItems = ""
foreach ($g in $generated) {
    $hItems += "    <ClInclude Include=`"$($g.File).h`" />`r`n"
    $cItems += "    <ClCompile Include=`"$($g.File).cpp`" />`r`n"
}
$hItems += "    <ClInclude Include=`"Dialog_Smfd_Analog_All.h`" />`r`n"
if ($proj -notmatch "Dialog_Smfd_Analog_401.h") {
    $proj = $proj.Replace("    <ClInclude Include=`"Dialog_Smfd_Analog.h`" />", "    <ClInclude Include=`"Dialog_Smfd_Analog.h`" />`r`n" + $hItems)
    $proj = $proj.Replace("    <ClCompile Include=`"Dialog_Smfd_Analog.cpp`" />", "    <ClCompile Include=`"Dialog_Smfd_Analog.cpp`" />`r`n" + $cItems)
}
Set-Content -Path $projPath -Value $proj -Encoding UTF8

# filters
$filtPath = Join-Path $root "ATI_UT.vcxproj.filters"
$filt = Get-Content $filtPath -Raw
$hFilt = ""
$cFilt = ""
foreach ($g in $generated) {
    $hFilt += "    <ClInclude Include=`"$($g.File).h`">`r`n      <Filter>Header Files</Filter>`r`n    </ClInclude>`r`n"
    $cFilt += "    <ClCompile Include=`"$($g.File).cpp`">`r`n      <Filter>Source Files</Filter>`r`n    </ClCompile>`r`n"
}
$hFilt += "    <ClInclude Include=`"Dialog_Smfd_Analog_All.h`">`r`n      <Filter>Header Files</Filter>`r`n    </ClInclude>`r`n"
if ($filt -notmatch "Dialog_Smfd_Analog_401.h") {
    $filt = $filt.Replace("    <ClInclude Include=`"Dialog_Smfd_Analog.h`">", $hFilt + "    <ClInclude Include=`"Dialog_Smfd_Analog.h`">")
    $filt = $filt.Replace("    <ClCompile Include=`"Dialog_Smfd_Analog.cpp`">", $cFilt + "    <ClCompile Include=`"Dialog_Smfd_Analog.cpp`">")
}
Set-Content -Path $filtPath -Value $filt -Encoding UTF8

Write-Host "Generated $($generated.Count) dialog classes."
Write-Host "Next IDD value: $idVal"
