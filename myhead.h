#pragma once

/*This function will be called when terminate() function is invoked by runtime*/
void my_terminate_handler(void);

/*This will be called when unexpected() is invoked by runtime*/
void my_unexcepted_handler(void);