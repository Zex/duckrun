<?php

echo '<html>';
echo '<head>';
echo '<title>DuckRun !</title>';
echo '</head>';
echo '<body style="background-color:black;color:yellow">';
#echo '<body bgcolor=black color=yellow>';
echo '<h3><center>DuckRun !</center></h3>';

$conn = mysqli_connect("localhost", "duckadm", "riskcud");
mysqli_select_db($conn, "duckrun");

$res = mysqli_query($conn, "select * from duckinfo");

echo '<table border=3 width=auto heigh=auto colspan=5 align=center margin=0 padding=0>';
echo '<tr bgcolor=darkblue>';
echo '<th>Email</th><th>Birth Day</th><th>Class</th></th>';
echo '</tr>';

while ($row = mysqli_fetch_row($res)) {
	echo '<tr>';
	echo '<td>'.$row[0].'</td> <td>'.$row[1].'</td> <td>'.$row[2].'</td>';
	echo '</tr>';
}
echo '</table>';
mysqli_close($conn);

echo '</body>';
echo '</html>';
?>
