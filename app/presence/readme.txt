This application gives an overview of the presence of single employees.
They may themselves edit their data via a webpage with table based on weekdays.
Exit this server programme using the key combination <ctrl>+<c>!

Use a URL like:
http://localhost:80/?action=send-index

Or some other port number for testing, since it does not require root access:
http://localhost:1971/?action=send-index

CAUTION! The reserved service ports 0..1023 can sometimes only be
used when running the cybol application as "root" user (Administrator).
In such cases, the cyboi interpreter might return an error message like:
"TEST: startup bsd socket bind error EACCES: 13"

The "nmap" tool may be used to find out about active service ports, e.g.:
nmap localhost

SOFTWARE DESIGN / LOGICAL ARCHITECTURE:

1 Two-Layer Architecture

The application architecture does NOT use a three-layer model like:
    wui - domain - database
but instead just a two-layer model as follows:
    wui - database
The introduction of a "domain" layer makes sense
ONLY if more than just one view (wui) is used.
Otherwise, the efficiency suffers without necessity.
However, a directory called "domain" is used for storing
permanent values like weekdays, lecturers, choices.

2 Single-Click State Change

2.1 Ajax

One option to change values would be to do it locally
on the client, that is in the web browser, using JavaScript.
This requires too much effort for such a simple application.

2.2 Buttons

An alternative would be to store state changes on the server
but only write them into the database files,
when the user clicks on a "Save" button or the like.
This solution would require locking techniques,
since many users might access the server in parallel,
which is too much effort for such a simple application.

2.3 Direct Storage

The implemented architecture manipulates values directly
in the web user interface (wui) and stores them in the
corresponding database file at once.
This might be slightly less efficient, but makes locking superfluous.
