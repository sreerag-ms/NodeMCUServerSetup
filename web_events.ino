void pack_events()
{
  char opt[50] , i = 0;
  char opt_array[500];
  String options = "";

  for(i=0;i<event_p;i++)
  {
    sprintf(opt, "<option value=\"%02d:%02d %d %d %d\">%02d:%02d</option>\n", event[i][0],event[i][1],event[i][2],event[i][3],event[i][4],event[i][0],event[i][1]);
    options = options + opt;
    //Serial.println(opt);
  }

  options.toCharArray(opt_array, sizeof(opt_array));
  
  snprintf_P(html, sizeof(html), Time_page3, opt_array); //options.to
  //Serial.println(html);
}
