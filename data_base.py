from firebase import firebase
firebase=firebase.FirebaseApplication('https://attendancesystem-6c7c0.firebaseio.com/',None)



control=firebase.post('presentStudents', 2 )

