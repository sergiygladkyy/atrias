#ifndef BENCHTOP_DEFINITIONS
#define BENCHTOP_DEFINITIONS

/*-------------------------------------------------*/
/*------ Calibration Values for Benchtop Leg ------*/
/*-------------------------------------------------*/
#define BENCHTOP_LEG_A_CALIB_VAL       4294967295LL
#define BENCHTOP_LEG_B_CALIB_VAL       263616696LL

#define BENCHTOP_LEG_A_RAD_PER_CNT   9.8039216e-09
#define BENCHTOP_LEG_B_RAD_PER_CNT  -9.8039216e-09

#define BENCHTOP_TRAN_A_CALIB_VAL      197682859LL
#define BENCHTOP_TRAN_B_CALIB_VAL      198854199LL

#define BENCHTOP_TRAN_A_RAD_PER_CNT  9.8039216e-09
#define BENCHTOP_TRAN_B_RAD_PER_CNT -9.8039216e-09

#define BENCHTOP_MOTOR_A_DIRECTION             1.0
#define BENCHTOP_MOTOR_B_DIRECTION            -1.0




// Ignore the lines below, they are used for the include magic.
#ifdef INCLUDE_LEFT_LEG
#define LEFT_LEG_A_CALIB_VAL     BENCHTOP_LEG_A_CALIB_VAL
#define LEFT_LEG_B_CALIB_VAL     BENCHTOP_LEG_B_CALIB_VAL

#define LEFT_LEG_A_RAD_PER_CNT   BENCHTOP_LEG_A_RAD_PER_CNT
#define LEFT_LEG_B_RAD_PER_CNT   BENCHTOP_LEG_B_RAD_PER_CNT

#define LEFT_TRAN_A_CALIB_VAL    BENCHTOP_TRAN_A_CALIB_VAL
#define LEFT_TRAN_B_CALIB_VAL    BENCHTOP_TRAN_B_CALIB_VAL 

#define LEFT_TRAN_A_RAD_PER_CNT  BENCHTOP_TRAN_A_RAD_PER_CNT
#define LEFT_TRAN_B_RAD_PER_CNT  BENCHTOP_TRAN_B_RAD_PER_CNT

#define LEFT_MOTOR_A_DIRECTION   BENCHTOP_MOTOR_A_DIRECTION
#define LEFT_MOTOR_B_DIRECTION   BENCHTOP_MOTOR_B_DIRECTION
#endif

#ifdef INCLUDE_RIGHT_LEG
#define RIGHT_LEG_A_CALIB_VAL    BENCHTOP_LEG_A_CALIB_VAL
#define RIGHT_LEG_B_CALIB_VAL    BENCHTOP_LEG_B_CALIB_VAL

#define RIGHT_LEG_A_RAD_PER_CNT  BENCHTOP_LEG_A_RAD_PER_CNT
#define RIGHT_LEG_B_RAD_PER_CNT  BENCHTOP_LEG_B_RAD_PER_CNT

#define RIGHT_TRAN_A_CALIB_VAL   BENCHTOP_TRAN_A_CALIB_VAL
#define RIGHT_TRAN_B_CALIB_VAL   BENCHTOP_TRAN_B_CALIB_VAL 

#define RIGHT_TRAN_A_RAD_PER_CNT BENCHTOP_TRAN_A_RAD_PER_CNT
#define RIGHT_TRAN_B_RAD_PER_CNT BENCHTOP_TRAN_B_RAD_PER_CNT

#define RIGHT_MOTOR_A_DIRECTION  BENCHTOP_MOTOR_A_DIRECTION
#define RIGHT_MOTOR_B_DIRECTION  BENCHTOP_MOTOR_B_DIRECTION
#endif

#endif //BENCHTOP_DEFINITIONS
