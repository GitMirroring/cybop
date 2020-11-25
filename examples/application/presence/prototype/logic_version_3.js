function change(td) {

    if (td.classList.contains('teaching')) {

        td.innerHTML = "Heimarbeit";
        td.classList.remove('teaching');
        td.classList.add('homeoffice');
        td.classList.remove('bg-success');
        td.classList.add('bg-danger');

    } else if (td.classList.contains('homeoffice')) {

        td.innerHTML = "Urlaub";
        td.classList.remove('homeoffice');
        td.classList.add('holiday');

    } else if (td.classList.contains('holiday')) {

        td.innerHTML = "Lehre/Büro";
        td.classList.remove('holiday');
        td.classList.add('teaching');
        td.classList.remove('bg-danger');
        td.classList.add('bg-success');
    }
}
