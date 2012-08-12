/**
 * Deserialises the percent-encoded character data into non-percent-encoded character data.
 *
 * @param p0 the destination data (pointer reference)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source data position (pointer reference)
 * @param p4 the source count remaining
 */
void deserialise_percent_encoding(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise percent-encoding.");

    // The character value.
    //?? TODO: Is "unsigned char" needed due to bigger size?
    unsigned char v = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    /*??
    // Decode integer.
    // A percent-encoding is a hexadecimal value consisting of two digits.
    // Therefore, a size of two is handed over as parametre here.
    deserialise_integer((void*) &v, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *pos, (void*) NUMBER_2_INTEGER_STATE_CYBOI_MODEL);
    */

    //
    //?? --- The following code is temporary and should be moved into an own file!
    //

/*??
    // The temporary null-terminated string.
    void* tmp = *NULL_POINTER_STATE_CYBOI_MODEL;
    int tmpc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int tmps = *NUMBER_3_INTEGER_STATE_CYBOI_MODEL;

    // Allocate temporary null-terminated string.
    allocate_array((void*) &tmp, (void*) &tmps, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Copy original string to temporary null-terminated string.
    overwrite_array((void*) &tmp, *pos, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_2_INTEGER_STATE_CYBOI_MODEL, tmpc, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, tmpc, tmps, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    // Add string termination to temporary null-terminated string.
    // The source count is used as index for the termination character.
    overwrite_array((void*) &tmp, (void*) NULL_CONTROL_ASCII_CHARACTER_CODE_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, tmpc, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, tmpc, tmps, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

    // The tail variable is useless here and only needed for the string
    // transformation function. If the whole string array consists of
    // many sub strings, separated by space characters, then each sub
    // string gets interpreted as integer number.
    // The tail variable in this case points to the remaining sub string.
    char* tail = (char*) *NULL_POINTER_STATE_CYBOI_MODEL;

    // Initialise error number.
    // It is a global variable/ function and other operations
    // may have set some value that is not wanted here.
    errno = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Set integer value.
    //
    // Transform string to integer value.
    // The third parametre is the number base:
    // 0 - tries to automatically identify the correct number base
    // 8 - octal, e.g. 083
    // 10 - decimal, e.g. 1234
    // 16 - hexadecimal, e.g. 3d4 or, optionally, 0x3d4
    v = strtol((char*) tmp, &tail, *NUMBER_16_INTEGER_STATE_CYBOI_MODEL);

//??    fwprintf(stdout, L"TEST tmp: %s\n", (char*) tmp);
//??    fwprintf(stdout, L"TEST v: %i\n", v);

    if (errno != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise integer. An error (probably overflow) occured.");
    }

    // Deallocate temporary null-terminated string.
    deallocate_array((void*) &tmp, (void*) &tmps, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

    //
    //?? --- The code above is temporary and should be moved into an own file!
    //

    overwrite_array(p0, (void*) &v, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, p1, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

    move_position(p3, p4, (void*) NUMBER_2_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
*/
}
