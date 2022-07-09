/**
 * Assign setActiveLink function to all links.
 */
function assignSetActiveLinkFunction() {

    // Get link node list.
    const l = document.querySelectorAll("nav a");

    // Process nodes one by one.
    for (let n of l) {

        // Add function to node.
        n.onclick = setActiveLink;
    }
}

/**
 * Assign active class to clicked link, after having
 * removed it from the link that last contained it.
 *
 * @param e the event
 */
function setActiveLink(e) {

    // Get event source (clicked link).
    var s = e.target;
    // Get active link list.
    let l = document.querySelectorAll("nav a.active");

    for (let n of l) {

        // Remove active class from link that last contained it.
        n.classList.remove("active");
    }

    // Add active class to clicked link.
    s.classList.add("active");
}

assignSetActiveLinkFunction();
