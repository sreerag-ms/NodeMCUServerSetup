void add_event(String eventTime,String eventNo1,String eventNo2,String eventNo3)
{
  char Time[10];
  char i;
  
  eventTime.toCharArray(Time,8);
  ev_h = ((Time[0] - '0')*10)+(Time[1] - '0');
  ev_m = ((Time[3] - '0')*10)+(Time[4] - '0');
  ev_1 = eventNo1.toInt();
  ev_2 = eventNo2.toInt();
  ev_3 = eventNo3.toInt();

  for(i=0; i < event_p; i++)
  {
     if(event[i][0] == ev_h && event[i][1] == ev_m)
      break;
  }
  if(ev_1 || ev_2 || ev_3)
  {
    Serial.println("Save Event");
    if(i < 25)
    {
      event[i][0] = ev_h;
      event[i][1] = ev_m;
      event[i][2] = ev_1;
      event[i][3] = ev_2;
      event[i][4] = ev_3;
      event_p++;
    }
  }
  
  /*if(ev_1 || ev_2 || ev_3)
  {
    Serial.println("Save Event");
    if(event_p < 25)
    {
      event[event_p][0] = ev_h;
      event[event_p][1] = ev_m;
      event[event_p][2] = ev_1;
      event[event_p][3] = ev_2;
      event[event_p][4] = ev_3;
      event_p++;
    }
  }
  else
  {
    Serial.println("Erase Event");
  }*/
  //event[25][5]
  Serial.println(eventTime);
  Serial.println(ev_h);
  Serial.println(ev_3);
}
