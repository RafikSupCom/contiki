// project-conf.h
#ifndef PROJECT_CONF_H_
#define PROJECT_CONF_H_

#define LOG_CONF_LEVEL_RPL LOG_LEVEL_INFO

// Your custom macro for DIO probability logic
#define N_MIN_TARGET 10

// Optional: force minimal trickle behavior
#define RPL_CONF_DIO_REDUNDANCY 255
#define RPL_CONF_DIO_INTERVAL_MIN 14
#define RPL_CONF_DIO_INTERVAL_DOUBLINGS 0

#endif /* PROJECT_CONF_H_ */

