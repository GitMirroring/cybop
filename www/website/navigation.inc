<!--
    The class "fixed-top" causes the content FOLLOWING the navbar
    to NOT begin after the navbar, but from the top of the page instead,
    so that the navbar covers the beginning of the content.
    Therefore, a PADDING has to be set here.
    A padding is used since it shows the SAME background COLOR as the navbar,
    whilst a margin shows the background of the html page body.
-->
<header style="padding-bottom: 64px;">

    <!--
        CAUTION! Do NOT apply the class "navbar-light", since it hinders
        changing the color values of anchor "a" link pseudo classes.
    -->
    <nav class="navbar navbar-expand-lg fixed-top justify-content-left shadow-sm">

        <div class="container">

            <!-- Brand/logo -->
            <a href="/" class="navbar-brand" style="font-size: 24pt; font-weight: bold; text-decoration: none;">
                <span style="color: #5287ce;">CYBOP</span>
                <span style="color: #aed6f2; margin-right: 50px;">Project</span>
<!--
                <img src="/logo.png" alt="CYBOP Project Logo" style="height: 50px; margin-left: 20px; margin-right: 50px;"/>
-->
            </a>

            <!-- Toggler/collapsibe button -->
            <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#menu" aria-controls="menu" aria-expanded="false" aria-label="Toggle Navigation">
                <span class="navbar-toggler-icon"></span>
            </button>

            <!-- Actual navigation bar -->
            <div class="collapse navbar-collapse" id="menu">
                <!--
                    CAUTION! The left padding has to be given as CSS STYLE.
                    Defining it for the pseudo class of nav-item does NOT work.
                    Probably, the reason is the class "justify-content-left" applied to the "nav" tag above,
                    which adjusts horizontal paddings automatically.
                -->
                <ul class="navbar-nav">
                    <li class="nav-item">
                        <a href="/documentation/" class="nav-link" style="padding-left: 40px; padding-right: 40px;">Documentation</a>
                    </li>
                    <li class="nav-item">
                        <a href="/download/" class="nav-link" style="padding-left: 40px; padding-right: 40px;">Download</a>
                    </li>
                    <li class="nav-item">
                        <a href="/tutorial/" class="nav-link" style="padding-left: 40px; padding-right: 40px;">Tutorial</a>
                    </li>
                    <li class="nav-item">
                        <a href="/development/" class="nav-link" style="padding-left: 40px; padding-right: 40px;">Development</a>
                    </li>
                    <li class="nav-item">
                        <a href="/publication/" class="nav-link" style="padding-left: 40px; padding-right: 40px;">Publication</a>
                    </li>
                    <li class="nav-item">
                        <a href="/support/" class="nav-link" style="padding-left: 40px; padding-right: 40px;">Support</a>
                    </li>
                </ul>
            </div>

        </div>

    </nav>

</header>
