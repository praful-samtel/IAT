#ifndef _Macros_H
#define _Macros_H


#define SIMULATE
#undef ILT_UPGRADE
#define ILT_NEW
#undef ADVCARD

#define PCI1711_1	1	                                 // PCI 1711 device index
#define VRGType		4
// test bench Macros
//#define PRELIM_TEST				1
#define VISUAL_INSPECTION	              1
#define MECH_DIMENSIONS						2
#define BONDING_AND_INSULATION_RESISTANCE 3
#define POWER_CONSUMPTION                 4
#define BEZEL_TESTS                       5
#define ATTITUDE_SENSOR_MODULE_TEST       6
#define LCD_DISPLAY_TEST				  7
#define OPTICAL_TESTS                     8
#define LCD_PANEL_CHECKS                  9
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////3-ATI//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////BEL////////////////////////////////////////////////////////////////////////////////
#define DEBUG422         1
#define PITCH_ROLL       1			// Adarsh : 09/04/2025 enablde to read the data and verify


#define DO_28VDC	        1
#define DO_5VAC         	2
#define DNS				    3
#define DISPLAY_VALID	    4
#define DO_5VDC		        5
#define DISPLAY_TEST		6
//#define DAY_NIGHT	    	7
#define AUTO_MANUAL	    	8

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define START_CNT  0
#define MAX_ADR_CNT 35
#define MAX_MIL_COUT 15
#define RS422_TEST  7
#ifdef DU_CONFIG2 
// test bench Macros
#define PRELIM_TEST				1


#endif

#define DU_ATP_MAX_NO_OF_TEST			300
#define DU_ATP_MIN_TEST_ID				101
#define DU_ATP_MAX_TEST_ID				1400
#define DU_ATP_MAX_NO_OF_SUBTEST		80

#define ENABLE_232
//-------------------------------------------------------------------------------------
//Button wizard macros
#define TOTAL_SLIDER_BUTTONS		6//5
#define MAX_VIEW_PER_BUTTON			20
#define VIEW_ARRAY_INIT				4,9,10,9,8,1

//-------------------------------------------------------------------------------------
#define MAX_LOOKUP_SIZE				100
#define MAX_LOOKUP_STRSIZE			100
#define	MAX_MESSAGES				5

#define		RED_COLOR				RGB(180,0,0)
#define		GREEN_COLOR				RGB(0,180,0)
#define		DARK_GREEN_COLOR		RGB(0,255,0)
#define		WHITE_COLOR				RGB(255,255,255) 
#define		BLUE_COLOR				RGB(0,0,180)
#define		BLACK_COLOR				RGB(0,0,0)
#define		CYAN_COLOR				RGB(0,255,255)
#define		WINGRAY_COLOR			RGB(0xd6,0xd3,0xce)

//table color
#define		MGRAY_COLOR				RGB(0xf7,0xf3,0xf7)
#define		LPINK_COLOR				RGB(0xe7,0xff,0xf7)
#define		SDU_PARAM_UPLD_CMD		1
#define		SDU_CHANNEL				1
#define		SDU						1
#define		SIPU					2
#define		SDU_PROGRAM_UPLD_CMD	3
#define		SIPU_PROGRAM_UPLD_CMD	4
#define		SIPU_FLG_UPLD_CMD		5



#define		LIGHT_OFF				0
#define		GREEN_LIGHT				1
#define		RED_LIGHT				2
#define     FAIL                    99
#define		WM_CUSTOM_OPEN			(WM_USER + 1)
#define		WM_CUSTOM_PRINT			(WM_USER + 2)
#define		WM_CUSTOM_DATAUPDATE	(WM_USER + 3)
#define		WM_CUSTOM_CLICK			(WM_USER + 4)


#define PUMP_MESSAGE_IF(msg)           if(::PeekMessage(&msg, NULL, 0, 0,PM_REMOVE)) {	\
									   ::TranslateMessage(&msg);					\
                            		   ::DispatchMessage(&msg);						\
									}                                   

#define PUMP_MESSAGE(msg)           while(::PeekMessage(&msg, NULL, 0, 0,PM_REMOVE)) {	\
									   ::TranslateMessage(&msg);					\
                            		   ::DispatchMessage(&msg);						\
									}                                   



#define PUMP_MESSAGE_NONMOUSE(msg)  if(::PeekMessage(&msg, NULL, 0, 0,PM_REMOVE)) {								\
										if( !(((msg.message >= WM_MOUSEFIRST)&&(msg.message <= WM_MOUSELAST))||	\
										((msg.message >= WM_KEYFIRST)&&(msg.message <= WM_KEYLAST))) ){			\
											::TranslateMessage(&msg);											\
											::DispatchMessage(&msg);											\
										}																		\
									}

typedef		unsigned short			COMMAND_ID;
typedef		unsigned short			*PCOMMAND_ID;

#define DISABLE					0	
#define ENABLE					1
	
#define ODD_PARITY                  0
#define EVEN_PARITY                 1
#define SDI_0		                0
#define SDI_1		                1
#define SDI_2		                2
#define SSM_0		                0
#define SSM_1		                1
#define SSM_2		                2
#define SSM_OK		                3

////////////////////////////////////////////////SIPU Macros/////////////////////////////////////
#define IT_INFINITE					1

#define IT_ENABLE				1
#define IT_DISABLE				0

/*Parameter Range */
#define START 0
#define END 17


/* Macros For Drawings */
#define COLOR_WHITE			255,255,255
#define COLOR_BLACK			0,0,0
#define COLOR_GREEN			0,255,0
#define COLOR_AMBER			254,220,140
#define COLOR_RED			255,0,0
#define COLOR_GREY			128,128,128
#define COLOR_BLUE			0,0,255
#define X_SCREEN_OFFSET		 50	
#define Y_SCREEN_OFFSET		 50 	
#define AUTO_MODE_TOTAL_MODULE 0

// DU type
#define DU_NOT_FOUND		0
#define CONFIG1				0
#define CONFIG2				1


// test type
#define MFD_ATP		0
#define ILT_SELFTEST	1
#define ILT_CENTER_LUM_METER	2
#define IAT_SELFTEST	1
#define IAT_SIMULATION	2



// ITB self test macros
#define LED_STATUS_ON					1
#define LED_STATUS_OFF					0
#define LED_STATUS_DISABLE				2
#define SELF_TEST_IOBRD					1
#define SELF_TEST_28VDC1				2
#define SELF_TEST_28VDC2				3
#define SELF_TEST_SMD_ON				4
#define SELF_TEST_115VACPH_A			5
#define SELF_TEST_115VACPH_B			6
#define SELF_TEST_115VACPH_C			7
#define SELF_TEST_115VACFREQ			8
#define SELF_TEST_RS422P1				9
#define SELF_TEST_RS422P2				10
#define SELF_TEST_5VAC_VOLTAGE			11
#define SELF_TEST_DNS					12
#define SELF_TEST_P1P2					13
#define SELF_TEST_MODE2					14
#define SELF_TEST_PRES					15
#define SELF_TEST_SMD_OK				16
#define SELF_TEST_PSM_VAL				17
#define SELF_TEST_LUMIN_METER			18
#define SELF_TEST_LPB_STR_LEN			4

#define IOBRD_COM_HEADER_BYTE1			0xFA
#define IOBRD_COM_HEADER_BYTE2			0xCE
#define IOBRD_COM_FOOTER_BYTE1			0xBA
#define IOBRD_COM_FOOTER_BYTE2			0x5E
#define MAX_BYTE_COUNT					10
#define MAX_TIMEOUT						10 // 10*500 msec

#define CMD_SELF_TEST_IOBOARD			1
#define SUBCMD_NA						0
#define BYTE_COUNT_1					1
#define BYTE_COUNT_2					2
#define DAYMODE_WHITE_MAX	1
#define DAYMODE_WHITE_MIN	2
#define DAYMODE_RED			3
#define DAYMODE_GREEN		4
#define DAYMODE_BLUE		5

#define NIGHTMODE_NON_NVG_WHITE_MAX		1
#define NIGHTMODE_NVG_WHITE_MAX			2
#define NIGHTMODE_NVG_WHITE_MIN			3

//ADC VALUE COMPUTATION MACROS
#define MAX_VOLT_MEASURE	2.9
#define MIN_VOLT_MEASURE	0.4
#define ADC_REF_VOLT		1.25
#define ADC_RESOLUTION		8192

#define MAXV28VDC_ON		30.0
#define MINV28VDC_ON		26.0
#define MAXV28VDC_OFF		2.0
#define MINV28VDC_OFF		0.0

//#define AC_VOL_RATIO_FACTOR_PHA		42.64200743494424
//#define AC_VOL_RATIO_FACTOR_PHB		42.64200743494424
//#define AC_VOL_RATIO_FACTOR_PHC		42.64200743494424
//#define DC_VOLT_RATIO_FACTOR		19.19583176224591
// upgrade 009
#define AC_VOL_RATIO_FACTOR_PHA		42.45
#define AC_VOL_RATIO_FACTOR_PHB		42.45
#define AC_VOL_RATIO_FACTOR_PHC		42.45
#define DC_VOLT_RATIO_FACTOR		19.79620520028109



#define MAX_AC_FREQ			420.0
#define MIN_AC_FREQ			380.0

#define MAXV115VAC_ON		117.0
#define MINV115VAC_ON		113.0
#define MAXV115VAC_OFF		0.5
#define MINV115VAC_OFF		0.0
#define NOMINAL_VAL_115AC	115
#define NOMINAL_VAL_5AC  	5.5

//#define ADC_5VAC_GAIN		4.80832480726128
// upgrade 009
//#define ADC_5VAC_GAIN		5.30
#define ADC_5VAC_GAIN		5.06836827711941

#define MAXV5VAC_ON			5.75
#define MINV5VAC_ON			5.25
#define MAXV5VAC_OFF		0.5
#define MINV5VAC_OFF		0.0
#define MIN_AC_115V			18.00

#define VAC115_THRESHOLD_MIN	107
#define VAC115_THRESHOLD_MAX	123
#define VAC5_THRESHOLD_MIN		4.8
#define VAC5_THRESHOLD_MAX		6.2

#define	ADC_MAX_VOL			2.9
#define	ADC_REF_VOL			1.25
#define ADC_RESOLUTION		8192 // 14 bit
#define ADC_28VDCOFFSET		0.50
#define CURR_SENS_CONV_FACTOR	0.186
#define MAX_28VDC_SAMPLES		8
#define MAX_CURR_SAMPLES		8
#define MINVALID_AC_CURR		0.150
#define MAXVALID_AC_CURR		0.700
#define MAX_RTRY_COUNT			4

// communication packet indexes
#define PACKET_HEADER1					0
#define PACKET_HEADER2					1
#define PACKET_CMD						2
#define PACKET_SUBCOMMAND				3
#define PACKET_DATA_SIZE				4
#define PACKET_DATA1					5
#define PACKET_DATA2					6
#define PACKET_CHECKSUM					7
#define PACKET_FOOTER1					8
#define PACKET_FOOTER2					9

// power supply and discrete output
#define DC1_28V							1
#define DC2_28V							2
#define DOP_SMD_ON						3
#define DOP_P1P2SELECT					4
#define DOP_DNS							5
#define DOP_MODE						6
#define AC_115VPHA						7
#define AC_115VPHB						8
#define AC_115VPHC						9
#define AC_5V							10
#define SMD_OK_ST						11
#define PRES_ST							12
#define PSMVAL_ST						13
#define SEL_ST							14


#define SUCCESS							0
#define FAILURE							1
#define ON								1
#define OFF								0
#define DAY								1
#define NIGHT							0
#define P1								1
#define P2								2
#define ATP								0
#define OPER							1
#define FPGA							0
#define FIELD							1


// IO board interface main commands
#define CMD_ID_DIP_SWITCHING		0x03
#define CMD_ID_DOP_READ				0x04
#define CMD_ID_DIP_READ				0x05
#define CMD_ID_VOLTAGE_READ			0x06
#define CMD_ID_CURRENT_READ			0x07
#define CMD_ID_RS422_LOOPBACK		0x08
#define CMD_ID_MFD_TYPE				0x09

// discrete switching commands
#define SUB_CMD_DIP_SWITCH_ALL			0x01
#define SUB_CMD_DIP_SWITCH_28VDC		0x02
#define SUB_CMD_DIP_SWITCH_28VDC2		0x03
#define SUB_CMD_DIP_SWITCH_115VACPHA	0x04
#define SUB_CMD_DIP_SWITCH_115VACPHB	0x05
#define SUB_CMD_DIP_SWITCH_115VACPHC	0x06
#define SUB_CMD_DIP_SWITCH_5VAC			0x07
#define SUB_CMD_DIP_SWITCH_SMD_ON		0x08
#define SUB_CMD_DIP_SWITCH_DNS			0x09
#define SUB_CMD_DIP_SWITCH_P1P2			0x0A
#define SUB_CMD_DIP_SWITCH_MODE2		0x0B
#define SUB_CMD_DIP_FSEL_ST				0x0C
#define SUB_CMD_DIP_PRES_ST				0x0D
#define SUB_CMD_DIP_PSMVAL_ST			0x0E
#define SUB_CMD_DIP_SMD_OK_ST			0x0F

// DOP read subcommands 
#define SUB_CMD_ID_DOP_READ_PRES		0x01
#define SUB_CMD_ID_DOP_READ_PSMVAL		0x02
#define SUB_CMD_ID_DOP_READ_SMDOK		0x03
#define SUB_CMD_ID_DOP_READ_DNS			0x04
#define SUB_CMD_ID_DOP_READ_P1P2		0x05
#define SUB_CMD_ID_DOP_READ_MODE		0x06
#define SUB_CMD_BENCH_MODE				0x07
#define DOP_READ_BACK_DUMMY_SUB			0x00

// voltage read subcommands
#define SUB_CMD_READ_VOL_28VDC			0x01
#define SUB_CMD_READ_VOL_115VAC_PHA		0x02
#define SUB_CMD_READ_VOL_115VAC_PHB		0x03
#define SUB_CMD_READ_VOL_115VAC_PHC		0x04
#define SUB_CMD_READ_VOL_5VAC			0x05
#define SUB_CMD_READ_VOL_SMDON			0x06
#define SUB_CMD_READ_VOL_P1P2			0x07
#define SUB_CMD_READ_VOL_DNS			0x08
#define SUB_CMD_READ_VOL_MODE2			0x09

// current read subcommands
#define SUB_CMD_READ_CURR_28VDC				0x01
#define SUB_CMD_READ_CURR_115VAC_PHA		0x02
#define SUB_CMD_READ_CURR_115VAC_PHB		0x03
#define SUB_CMD_READ_CURR_115VAC_PHC		0x04

// RS422 sub commands
#define SUB_CMD_RS422_1						0x01
#define SUB_CMD_RS422_2						0x02
#define HW_SETTLING_TIME					500
#define DIS_SETTLING_TIME					1000

// MFD TYPE sub COMMAND
#define SUB_MFD_TYPE						0x00

//macros for reading status of discretes
#define MASK_DNS						0x40
#define MASK_P1P2						0x80
#define NA								0x00
//optical checks macros
#define WAIT_CMFD_MAX_BRIT					300000
#define WAIT_CMFD_MIN_BRIT					20000

#define WAIT_SMD_MAX_BRIT					20000
#define WAIT_SMD_MIN_BRIT					10000


//Video Pattern Generator
#define VPG_BLACK		0x41
#define VPG_BLUE		0x42
#define VPG_GREEN		0x43
#define VPG_WHITE		0x44
#define VPG_RED			0x45
#define VPG_COL_BAR		0x46
#define VPG_GRY_SCALE	0x47

//115VAC PWR_INTFACE macros
#define VAC115_IDENTITY		45
#define VAC115_RESPONSE		12
#define PHASE_A			0x41
#define PHASE_B			0x42
#define PHASE_C			0x43
#define DEF_FREQ		400
#define CMFD_MOD0		0x00
#define CMFD_MOD2		0x02

#define HARDWARE	1

#define PORT_A0		0
#define PORT_A1		1

#define PCI_1711		0  

#define GAIN_0to10V		0
#define GAIN_0to5V		1

#define ADC_28VDC_VTG           0
#define ADC_5VDC_VTG	        2
#define ADC_DISPLAY_VALID_VTG	4
#define ADC_28VDC_CUR	        13
#define ADC_5VDC_CUR	        10



#define DO_28V_CURRENT_FACTER		2.98060185372566
#define DO_28V_CURRENT_OFFSET		0.15


#define ADC_SPARE1_CUR	12
#define ADC_SPARE2_VTG	6
#define ADC_SPARE2_CUR	14

#define ON			1
#define OFF			0
#define MAX_DEVICES 32

#define DO_28VDC	        1
#define DO_5VAC         	2
#define DO_BEZ		        5
#define DAY_NIGHT         		6
#define FC_RC	    	7
#define AUTO_MANUAL	    	8

/* IAT LRU ON OFF DISCRETE  */

#define ADC_ON              1
//#define ADC_OFF             
#define AHRS_ON             2
//#define AHRS_OFF 4
#define VOR_ON             3
#define TACAN_ON           4
//#define TACAN_OFF 6
#define GPS_FC_ON          5
//#define GPS_FC_OFF 8
#define GPS_RC_ON           6
//#define GPS_RC_OFF 10
#define ISIS_DU_FC_ON          7
//#define ISIS_DU_FC_OFF 12
#define ISIS_DU_RC_ON         8
//#define ISIS_DU_RC_OFF 14
#define SMFD_FC_ON         9
//#define SMFD_FC_OFF
#define SMFD_RC_ON             10
#define MFD_FC_ON          11
#define MFD_RC_ON         12



#define GAINDO_28VDC_V		10
#define GAIN115VAC_V	43.189
#define GAINDO_28VDC_I		185	
#define GAIN115VAC_I	185	

#define MAX_SAMPLE_CNT	64
#define MEAS_MAX_CURR_28V_HOFF	714
#define MEAS_MIN_CURR_28V_HOFF	300
#define MEAS_MAX_CURR_28V_HON	1071
#define MEAS_MIN_CURR_28V_HON	714

#define MEAS_NGHT_CURR_28V_HOFF	600
#define MEAS_NGHT_CURR_28V_HON	714

#define MAXTIMER_CNT	35

#define DO_Display_Valid		1.416
#define Condition_OK		2.000000
#define Discrete_Status		3

///////////////////////////////ISIS////////////////////////////////////////////
#define VOLT_28VDC_MIN	25.9999
#define VOLT_28VDC_MAX	30.0001

#define SAMPLE_ARINC_DATA 38571905


/* SMFD Discrete */
#define BusTie 1
#define Canopy 2
#define Ecsoff 3
#define EcsOvPr 4
#define AoaMute 5
#define AlarmMute 6
#define Demist 7
#define Starton 8





////////////////////////////////////////// ARINC429 MACROS /////////////////////////////////////////////////////////////

// Simulation loopback connections.  Change these values only when the
// corresponding unit's ARINC harness/channel assignment changes.
#define ISIS_SIM_LOOPBACK_TX_CHANNEL_X  0
#define ISIS_SIM_LOOPBACK_TX_CHANNEL_Y  1
#define ISIS_SIM_LOOPBACK_RX_PIN_P      8
#define ISIS_SIM_LOOPBACK_RX_PIN_Q      9

// Current ADC simulation code sends on TX 3 and receives on RX 9.  The
// duplicate values intentionally describe the single active ADC loopback.
// Update Y/Q when a second ADC loopback path is enabled in the hardware/code.
#define ADC_SIM_LOOPBACK_TX_CHANNEL_X   3
#define ADC_SIM_LOOPBACK_TX_CHANNEL_Y   3
#define ADC_SIM_LOOPBACK_RX_PIN_P       9
#define ADC_SIM_LOOPBACK_RX_PIN_Q       9


#define RESOLUTION_60 0.015625
#define RESOLUTION_61 0.015625
#define RESOLUTION_62 0.015625
#define RESOLUTION_173 0.002
#define RESOLUTION_174 0.002
#define RESOLUTION_173 0.002
#define RESOLUTION_203 1 ///////////////////////
#define RESOLUTION_204 1 ///////////////////////
#define RESOLUTION_205 0.00025 ///////////////////////
#define RESOLUTION_206 0.0625
#define RESOLUTION_212 16
#define RESOLUTION_234 0.1
#define RESOLUTION_235 0.001
#define RESOLUTION_242 0.03125
#define RESOLUTION_245 0.03125
#define RESOLUTION_246 0.03125
#define RESOLUTION_320 0.0055
#define RESOLUTION_324 0.01099
#define RESOLUTION_325 0.01099

#define ADC_RESOLUTION_203  (0.5f)
#define ADC_RESOLUTION_204  (0.5f)
#define ADC_RESOLUTION_205  (1.0f / 64000.0f)
#define ADC_RESOLUTION_206  (1.0f / 256.0f)
#define ADC_RESOLUTION_212  (0.25f) 

#define LABEL_061 0x8c
#define LABEL_062 327
#define LABEL_155 0xb6
#define LABEL_156 0x76
#define LABEL_157 0xF6
#define LABEL_173 0xde
//#define LABEL_174 0174
#define LABEL_174 0x3e
#define LABEL_177 0177
//#define LABEL_203 0203
#define LABEL_203 0xc1
//#define LABEL_204 0204
#define LABEL_204 0x21
//#define LABEL_205 0205
#define LABEL_205 0xa1
//#define LABEL_206 0206
#define LABEL_206 0x61
//#define LABEL_212 0212
#define LABEL_212 0x51
//#define LABEL_212 0x2B
#define LABEL_213 0XD1
#define LABEL_210 0x4D
//#define LABEL_222 0x92
#define LABEL_234 0234
#define LABEL_235 0xb9
#define LABEL_242 0242
#define LABEL_245 0245
#define LABEL_246 0246
#define LABEL_274 0274
#define LABEL_306 0307
#define LABEL_307 0307
#define LABEL_320 0x0b
#define LABEL_324 0x2b
//#define LABEL_325 0325
#define LABEL_325 0xab
#define LABEL_326 0x6b
#define LABEL_327 0xeb
#define LABEL_330 0x1b
#define LABEL_331 0x9b
#define LABEL_332 0x5b
//#define LABEL_333 0333
#define LABEL_333 0xdb


#define GET_MAX_PATH 2500

#define NOMINAL_VALUE_PITCH_0 0
#define MINIMUM_VALUE_PITCH_0 -0.49
#define MAXIMUM_VALUE_PITCH_0 0.51

#define NOMINAL_VALUE_ROOL_0 0
#define MINIMUM_VALUE_ROOL_0 -0.49
#define MAXIMUM_VALUE_ROOL_0 0.51

#define BIG_ENDIAN
#define DATA_RD_TIME	2000
#define TIMER_	100
//#define DATA_RD_TIME	3000
//#define LITTLE_ENDIAN




typedef struct _arinc_bitfield_
{
/*#ifdef BIG_ENDIAN
	unsigned int parity: 1;
	unsigned int SSM:    2;
	unsigned int sign:    1;
    unsigned int data:    18;										
    unsigned int SDI:    2;
    unsigned int label:  8;*/
//#ifdef LITTLE_ENDIAN
	unsigned int label:  8;
	unsigned int SDI:    2;
	unsigned int data:    18;
	unsigned int sign:    1;
	unsigned int SSM:    2;
	unsigned int parity: 1;

    
//#endif // LITTLEENDIAN
}
ARINC_PACKET;

typedef union _Arinc
{
	unsigned int a;
	ARINC_PACKET bit;
}ARINC_PACKET1;

typedef struct _pitch_angle_bitfield_
{
/*#ifdef BIG_ENDIAN
	unsigned int parity: 1;
	unsigned int SSM:    2;
    unsigned int data:    15;
    unsigned int reserv: 4;
    unsigned int SDI:    2;
    unsigned int label:  8;
#elif LITTLE_ENDIAN*/
	unsigned int label:  8; 
	unsigned int SDI:    2;
	unsigned int reserv: 4;
	signed int data:    15;
	//unsigned int sign:    1;
	unsigned int SSM:    2;
	unsigned int parity: 1;
    
//#endif // LITTLEENDIAN
}
PITCH_ANGLE_PACKET;

typedef struct _roll_angle_bitfield_
{
/*#ifdef BIG_ENDIAN
	unsigned int parity: 1;
	unsigned int SSM:    2;
    unsigned int data:    15;	
    unsigned int reverv: 4;
    unsigned int SDI:    2;
    unsigned int label:  8;
#elif LITTLE_ENDIAN*/
	unsigned int label:  8;
	unsigned int SDI:    2;
	unsigned int reverv: 4;
	signed int data:    15;
	unsigned int SSM:    2;
	unsigned int parity: 1;
    
//#endif // LITTLEENDIAN
}
ROLL_ANGLE_PACKET;

typedef struct _static_pressure_bitfield_
{
/*#ifdef BIG_ENDIAN
	unsigned int parity: 1;
	unsigned int SSM:    2;
    unsigned int data:    17;	
    unsigned int reverv: 2;
    unsigned int SDI:    2;
    unsigned int label:  8;
#elif LITTLE_ENDIAN*/
	unsigned int label:  8;
	unsigned int SDI:    2;
	//unsigned int reverv: 2;
	unsigned int data:    18;
	unsigned int sign:    1;
	unsigned int SSM:    2;
	unsigned int parity: 1;
    
//#endif // LITTLEENDIAN
}
STATIC_PRESSURE_PACKET;

typedef struct _non_baro_corrected_altitude_bitfield_
{
/*#ifdef BIG_ENDIAN
	unsigned int parity: 1;
	unsigned int SSM:    2;
    unsigned int data:    18;	
    unsigned int reverv: 1;
    unsigned int SDI:    2;
    unsigned int label:  8;
#elif LITTLE_ENDIAN*/
	unsigned int label:  8;
	unsigned int SDI:    2;
	unsigned int reverv: 1;
	unsigned int data:    17;
	unsigned int sign:    1;
	unsigned int SSM:    2;
	unsigned int parity: 1;
    
//#endif // LITTLEENDIAN
}
NBC_ALTITUDE_PACKET;

typedef struct _baro_corrected_altitude_bitfield_
{
/*#ifdef BIG_ENDIAN
	unsigned int parity: 1;
	unsigned int SSM:    2;
    signed int data:    18;	
    unsigned int reverv: 1;
    unsigned int SDI:    2;
    unsigned int label:  8;
#elif LITTLE_ENDIAN*/
	unsigned int label:  8;
	unsigned int SDI:    2;
	unsigned int reverv: 1;
	signed int data:    17;
	unsigned int sign:    1;
	unsigned int SSM:    2;
	unsigned int parity: 1;
    
//#endif // LITTLEENDIAN
}
BC_ALTITUDE_PACKET;

typedef struct _mach_bitfield_
{
/*#ifdef BIG_ENDIAN
	unsigned int parity: 1;
	unsigned int SSM:    2;
    signed int data:    17;	
    unsigned int reverv: 2;
    unsigned int SDI:    2;
    unsigned int label:  8;
#elif LITTLE_ENDIAN*/
	unsigned int label:  8;
	unsigned int SDI:    2;
	unsigned int reverv: 2;
	unsigned int data:    16;
	unsigned int Sing:    1;
	unsigned int SSM:    2;
	unsigned int parity: 1;
    
//#endif // LITTLEENDIAN
}
MACH_PACKET;

typedef struct _Indicated_air_speed_bitfield_
{
/*#ifdef BIG_ENDIAN
	unsigned int parity: 1;
	unsigned int SSM:    2;
    signed int data:    17;	
    unsigned int reverv: 2;
    unsigned int SDI:    2;
    unsigned int label:  8;
#elif LITTLE_ENDIAN*/
	unsigned int label:  8;
	unsigned int SDI:    2;
	unsigned int reverv: 4;
	unsigned int data:    14;
	unsigned int Sign:    1;
	unsigned int SSM:    2;
	unsigned int parity: 1;
    
//#endif // LITTLEENDIAN
}
IAIR_SPEED_PACKET;

// ADC: bits 11..28 = magnitude/data, bit 29 = sign.
// No reserved bit at bit 11.
typedef struct _adc_bnr19_packet_
{
    unsigned int label  : 8;   // bits 1..8
    unsigned int SDI    : 2;   // bits 9..10
    unsigned int data   : 18;  // bits 11..28
    unsigned int sign   : 1;   // bit 29
    unsigned int SSM    : 2;   // bits 30..31
    unsigned int parity : 1;   // bit 32
} ADC_BNR19_PACKET;


typedef struct _heading_bitfield_
{
/*#ifdef BIG_ENDIAN
	unsigned int parity: 1;
	unsigned int SSM:    2;
    signed int data:    17;	
    unsigned int reverv: 2;
    unsigned int SDI:    2;
    unsigned int label:  8;
#elif LITTLE_ENDIAN*/
	unsigned int label:  8;
    unsigned int SDI:    2;
	unsigned int reverv: 3;
	signed int data:    16;
	unsigned int SSM:    2;
	unsigned int parity: 1;

//#endif // LITTLEENDIAN
}
HEADING_PACKET;


typedef struct _vertical_Speed_
{
/*#ifdef BIG_ENDIAN
	unsigned int parity: 1;
	unsigned int SSM:    2;
    signed int data:    17;	
    unsigned int reverv: 2;
    unsigned int SDI:    2;
    unsigned int label:  8;
#elif LITTLE_ENDIAN*/
	unsigned int label:  8;
    unsigned int SDI:    2;
	unsigned int reverv: 3;
	signed int data:    15;
	unsigned int Sign:    1;
	unsigned int SSM:    2;
	unsigned int parity: 1;

//#endif // LITTLEENDIAN
}
VERTICAL_SPEED;

typedef struct _total_pressure_
{
/*#ifdef BIG_ENDIAN
	unsigned int parity: 1;
	unsigned int SSM:    2;
    signed int data:    17;	
    unsigned int reverv: 2;
    unsigned int SDI:    2;
    unsigned int label:  8;
#elif LITTLE_ENDIAN*/
	unsigned int label:  8;
    unsigned int SDI:    2;
	//unsigned int reverv: 3;
	unsigned int data:    18;
	unsigned int Sign:    1;
	unsigned int SSM:    2;
	unsigned int parity: 1;

//#endif // LITTLEENDIAN
}
TOTAL_PRESSURE;


typedef struct _uncorrected_static_pressure
{

	unsigned int label:  8;
    unsigned int SDI:    2;
	unsigned int data:    18;
	unsigned int Sign:    1;
	unsigned int SSM:    2;
	unsigned int parity: 1;
}
UNCORRECTED_STATIC_PRESSURE;

typedef struct _Vor_Bearing_
{

	unsigned int label:  8;
    unsigned int SDI:    2;
	unsigned int marker:  4;
	unsigned int data:    12;
	unsigned int Sign:    1;
	unsigned int SSM:    2;
	unsigned int parity: 1;
}
vor_bearing;

typedef struct _pressure_altitude_
{
/*#ifdef BIG_ENDIAN
	unsigned int parity: 1;
	unsigned int SSM:    2;
    signed int data:    17;	
    unsigned int reverv: 2;
    unsigned int SDI:    2;
    unsigned int label:  8;
#elif LITTLE_ENDIAN*/
	unsigned int label:  8;
    unsigned int SDI:    2;
	unsigned int reverv: 1;
	unsigned int data:    17;
	unsigned int Sign:    1;
	unsigned int SSM:    2;
	unsigned int parity: 1;

//#endif // LITTLEENDIAN
}
PRESSURE_ALTITUDE;


typedef struct _Localizer_deviation_bitfield_
{
	unsigned int label:  8;
	unsigned int SDI:    2;
	unsigned int reverv: 6;
	unsigned int data:    13;
	unsigned int SSM:    2;
	unsigned int parity: 1;
}
LOCALIZER_DEVIATION;

typedef struct _Glide_slope_bitfield_
{
	unsigned int label:  8;
	unsigned int SDI:    2;
	unsigned int reverv: 6;
	unsigned int data:    13;
	unsigned int SSM:    2;
	unsigned int parity: 1;
}
GLIDE_SLOPE;

typedef struct _baro_CorrectionHg_bitfield_
{
	unsigned int label:  8;
	unsigned int SDI:    2;
	unsigned int data:    19;
	unsigned int SSM:    2;
	unsigned int parity: 1;
    
//#endif // LITTLEENDIAN
}
BARO_CORRECTIONHG;

typedef struct _yaw_rate_bitfield_
{
	unsigned int label:  8; 
	unsigned int SDI:    2;
	unsigned int reserv: 3;
	signed int data:    15;
	unsigned int sign:    1;
	unsigned int SSM:    2;
	unsigned int parity: 1;
    
//#endif // LITTLEENDIAN
}
YAW_RATE;

typedef struct _pitch_rate_bitfield_
{
	unsigned int label:  8; 
	unsigned int SDI:    2;
	unsigned int reserv: 3;
	signed int data:    15;
	unsigned int sign:    1;
	unsigned int SSM:    2;
	unsigned int parity: 1;
    
//#endif // LITTLEENDIAN
}
PITCH_RATE;

typedef struct _roll_rate_bitfield_
{
	unsigned int label:  8; 
	unsigned int SDI:    2;
	unsigned int reserv: 3;
	signed int data:    15;
	unsigned int sign:    1;
	unsigned int SSM:    2;
	unsigned int parity: 1;
    
//#endif // LITTLEENDIAN
}
ROLL_RATE;

typedef struct _longitud_Accel_bitfield_
{
	unsigned int label:  8; 
	unsigned int SDI:    2;
	unsigned int reserv: 6;
	signed int data:    12;
	unsigned int sign:    1;
	unsigned int SSM:    2;
	unsigned int parity: 1;
    
//#endif // LITTLEENDIAN
}
LONGITUDINAL_ACCELERATION;

typedef struct _lateral_Accel_bitfield_
{
	unsigned int label:  8; 
	unsigned int SDI:    2;
	unsigned int reserv: 6;
	signed int data:    12;
	unsigned int sign:    1;
	unsigned int SSM:    2;
	unsigned int parity: 1;
    
//#endif // LITTLEENDIAN
}
LATERAL_ACCELERATION;

typedef struct _normal_Accel_bitfield_
{
	unsigned int label:  8; 
	unsigned int SDI:    2;
	unsigned int reserv: 6;
	signed int data:    12;
	unsigned int sign:    1;
	unsigned int SSM:    2;
	unsigned int parity: 1;
    
//#endif // LITTLEENDIAN
}
NORMAL_ACCELERATION;

#endif




#define CMD_HEADER_INDEX0		0x00
#define CMD_HEADER_INDEX1		0x01
#define CMD_HEADER_INDEX2		0x02
#define CMD_HEADER_INDEX3		0x03

/*
#define CMD_DATA_INDEX0		0x0C
#define CMD_DATA_INDEX1		0x0D
#define CMD_DATA_INDEX2		0x0E
#define CMD_DATA_INDEX3		0x0F
*/

#define CMD_DATA_INDEX0		0x0A
#define CMD_DATA_INDEX1		0x0B
#define CMD_DATA_INDEX2		0x0C
#define CMD_DATA_INDEX3		0x0D

/*
#define CMD_DATA_INDEX4		0x10
#define CMD_DATA_INDEX5		0x11
#define CMD_DATA_INDEX6		0x12
#define CMD_DATA_INDEX7		0x13
*/

#define CMD_DATA_INDEX4		0x0E
#define CMD_DATA_INDEX5		0x0F
#define CMD_DATA_INDEX6		0x10
#define CMD_DATA_INDEX7		0x11

/*
#define CMD_DATA_INDEX8		0x14
#define CMD_DATA_INDEX9		0x15
#define CMD_DATA_INDEX10	0x16
#define CMD_DATA_INDEX11	0x17
*/
#define CMD_DATA_INDEX8		0x12
#define CMD_DATA_INDEX9		0x13
#define CMD_DATA_INDEX10	0x14
#define CMD_DATA_INDEX11	0x15

/*
#define CMD_DATA_INDEX12		0x18
#define CMD_DATA_INDEX13		0x19
#define CMD_DATA_INDEX14		0x1A
#define CMD_DATA_INDEX15		0x1B
*/

#define CMD_DATA_INDEX12	0x16
#define CMD_DATA_INDEX13	0x17
#define CMD_DATA_INDEX14	0x18
#define CMD_DATA_INDEX15	0x19

/*
#define CMD_DATA_INDEX16		0x0C
#define CMD_DATA_INDEX17		0x0D
#define CMD_DATA_INDEX18		0x0E
#define CMD_DATA_INDEX19		0x0F
*/

#define CMD_DATA_INDEX16	0x1A
#define CMD_DATA_INDEX17	0x1B
#define CMD_DATA_INDEX18	0x1C
#define CMD_DATA_INDEX19	0x1D
/*
#define CMD_DATA_INDEX20		0x10
#define CMD_DATA_INDEX21		0x11
#define CMD_DATA_INDEX22		0x12
#define CMD_DATA_INDEX23		0x13
*/
#define CMD_DATA_INDEX20		0x1E
#define CMD_DATA_INDEX21		0x1F
#define CMD_DATA_INDEX22		0x20
#define CMD_DATA_INDEX23		0x21

/*
#define CMD_DATA_INDEX24		0x14
#define CMD_DATA_INDEX25		0x15
#define CMD_DATA_INDEX26		0x16
#define CMD_DATA_INDEX27		0x17
*/

#define CMD_DATA_INDEX24		0x22
#define CMD_DATA_INDEX25		0x23
#define CMD_DATA_INDEX26		0x24
#define CMD_DATA_INDEX27		0x25

#define CMD_DATA_INDEX28		0x18
#define CMD_DATA_INDEX29		0x19
#define CMD_DATA_INDEX30		0x1A
#define CMD_DATA_INDEX31		0x1B

#define CMD_DATA_INDEX32		0x1C
#define CMD_DATA_INDEX33		0x1D
#define CMD_DATA_INDEX34		0x1E
#define CMD_DATA_INDEX35		0x1F

#define CMD_DATA_INDEX36		0x20
#define CMD_DATA_INDEX37		0x21
#define CMD_DATA_INDEX38		0x22
#define CMD_DATA_INDEX39		0x23
