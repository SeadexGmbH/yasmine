<table>
  <tr>  	
    <th>City</th>
    <th>Population</th>
	<th></th>
  </tr>
  $loop(cities)
  <tr>    
    <td>$if(is_capital)<b><p style="color:#1E90FF">$fi$var(city_name)$if(is_capital)</p></b>$fi</td>
    <td>$if(is_capital)<b><p style="color:#1E90FF">$fi$var(city_population)$if(is_capital)</p></b>$fi</td>
	<td>$if(is_capital)<b><p style="color:#1E90FF">$fi$template(city_type.gtpl)$if(is_capital)</p></b>$fi</td>	
  </tr>
  $pool
</table>