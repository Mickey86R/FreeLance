function getCookie(name){
  const cookie = document.cookie;
  const parts = cookie.split(';');
  var number;
  parts.forEach((item, i) => {
    if(item.indexOf(name) >= 0) number = item.split('=').pop();
  });
  return number;
}
