/*
 * The search strings.
 *
 * CAUTION! The cyboi html serialiser replaces quotation marks
 * not only in html markup, but also within javascript sections,
 * so that the functions will NOT work anymore.
 *
 * Therefore, these strings are defined as arrays of unicode codepoints,
 * so that quotation mark or apostrophe do NOT have to be used.
 *
 * The strings are:
 * nav_a = nav a
 * nav_a_active = nav a.active
 * active = active
 */
var nav_a = String.fromCodePoint(0x006E, 0x0061, 0x0076, 0x0020, 0x0061);
var nav_a_active = String.fromCodePoint(0x006E, 0x0061, 0x0076, 0x0020, 0x0061, 0x002E, 0x0061, 0x0063, 0x0074, 0x0069, 0x0076, 0x0065);
var active = String.fromCodePoint(0x0061, 0x0063, 0x0074, 0x0069, 0x0076, 0x0065);

/**
 * Assign class &#x22;active&#x22; to clicked link, after having
 * removed it from the link that last contained it.
 *
 * @param e the event
 */
function setActiveLink(e) {

    // Get event source (clicked link).
    var s = e.target;
    // Get active link list.
    let l = document.querySelectorAll(nav_a_active);

    for (let n of l) {

        // Remove class &#x22;active&#x22; from link that last contained it.
        n.classList.remove(active);
    }

    // Add class &#x22;active&#x22; to clicked link.
    s.classList.add(active);
}

/**
 * Assign function &#x22;setActiveLink&#x22; to all links.
 */
function assignSetActiveLinkFunction() {

    // Get link node list.
    const l = document.querySelectorAll(nav_a);

    // Process nodes one by one.
    for (let n of l) {

        // Add function to node.
        n.onclick = setActiveLink;
    }
}

assignSetActiveLinkFunction();
