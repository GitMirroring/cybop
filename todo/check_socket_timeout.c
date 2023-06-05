//
// System interface
//

#include <time.h> // time_t, time()

//
// The current calendar time.
//
// The type "time_t" is used to represent a simple calendar time.
// In iso c, it can be either an integer or a floating-point type.
//
// On posix-conformant systems, "time_t" is an integer type
// and its values represent the number of seconds elapsed
// since the epoch, which is 1970-01-01T00:00:00 UTC.
//
time_t t = time(*NULL_POINTER_STATE_CYBOI_MODEL);

//
// There ARE data available on the client.
//

check_client_element_available(p0, p4, p7, (void*) &c, (void*) &t);

if (p4 != *NULL_POINTER_STATE_CYBOI_MODEL) {

    time_t* t = (time_t*) p4;

    // The current calendar time as integer value.
    int ti = (int) *t;

//
// Reset sender client accepttime using the current calendar time,
// everytime new data traffic has been detected.
//

/**
 * Checks timeout of open but inactive client
 * and closes it if the timeout has been crossed.
 */

if (p10 != *NULL_POINTER_STATE_CYBOI_MODEL) {

    time_t* t = (time_t*) p10;

    // The accepttime.
    int a = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The timeout.
    void* to = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The accepttime with correct type.
    time_t at = (time_t) a;
    //
    // Calculate elapsed time (difference) between two calendar times.
    //
    // CAUTION! Since the type "time_t" might differ between platforms
    // (integer or floating-point), a simple subtraction might fail.
    // Therefore, the function "difftime" is used to compute the difference.
    //
    double d = difftime(*t, at);
    // The elapsed time (difference) as integer value.
    int di = (int) d;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_greater((void*) &r, (void*) &di, to);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // The timeout has been crossed.
        //

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Close client connexion due to crossed timeout.");
        fwprintf(stdout, L"Debug: Close client connexion due to crossed timeout. r: %i\n", r);

        // Remove element from client list.

        // Close client.
        shutdown_socket_close(p7);

