/**
 * Deserialises the percent-encoded character element into
 * a non-percent-encoded character element.
 *
 * @param p0 the destination data (pointer reference)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source data position (pointer reference)
 * @param p4 the source count remaining
 */
void deserialise_percent_encoding_vector_element(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise percent-encoding vector element.");

/*??
    // The unreserved characters.
    void* u = *pos;
    int uc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // The break flag.
    int b = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        if (*rem <= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            break;
        }

        select_percent_encoding_vector_element(p0, p1, p2, (void*) &b, p3, p4);

        if (b != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            break;

        } else {

            // Increment unreserved characters count.
            uc++;
        }
    }

    // Append any unreserved characters found up to here,
    // no matter whether an unreserved character follows
    // or no unreserved character at all was found.
    overwrite_array(p0, u, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) &uc, p1, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

    if (b != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        // A % sign was found that indicates a reserved character.
        deserialise_percent_encoding(p0, p1, p2, p3, p4);

        // Process further characters by calling decode function recursively.
        //
        // CAUTION! Only call this function if a reserved character was found.
        // Otherwise, the loop was left due to no more remaining characters,
        // so that nothing is left to be processed here.
        deserialise_percent_encoding_vector_element(p0, p1, p2, p3, p4);
    }
*/
}

/* PERCENT_ENCODING_VECTOR_DESERIALISER_SOURCE */
#endif
