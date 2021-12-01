function doOne(n) {
  let arr = Array(n)
  for (var i = 0; i < n; i++) {
    arr[i] = i + 1
  }
  return arr
}

function doTwo(arr) {
  var sum = 0
  for(let el of arr)
  	sum += el
  return sum
}

function doThree(arr) {
  var max = arr[0]
  for(let el of arr)
  	if(el > max) 
    	max = el
  return max
}

function doFour(arr) {
  var min = arr[0]
  for(let el of arr)
  	if(el < min) 
    	min = el
  return min
}

function doFive(arr) {
  var even = Array()
  for(let el of arr)
  	if(el % 2 == 0) 
    	even.push(el)
  return even
}
