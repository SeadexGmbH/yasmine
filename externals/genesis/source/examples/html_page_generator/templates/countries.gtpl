<!DOCTYPE html>
<html>
<head>
<style>
table {
    font-family: arial, sans-serif;
    border-collapse: collapse;
    width: 95%;
}

td, th {
    border: 1px solid #E7C324;;
    text-align: left;
    padding: 3px;
	height: 20px;
}

tr:nth-child(even) {
    background-color: #252525;
}

body{
background-color:#262626;
color: #E7C324;
}

hr{
color: #E7C324;
}
</style>

<title>Population of big cities</title>

</head>
<body>

<h1>Population of big cities.</h1>
<p>List of countries:</p>
<p style="font-size:12px">*The capital is marked <b>bold</b> and <a style="color:#1E90FF">blue</a></p>
$loop(countries)
<h3> <b>$var(country_name)</b></h3>
$template(country_table.gtpl)
<hr>
$pool

</body>
</html>