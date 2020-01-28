from firebase import firebase
from firebase_admin import db
import firebase_admin
from firebase_admin import credentials
firebase=firebase.FirebaseApplication('https://attendancesystem-6c7c0.firebaseio.com/',None)


get_data= firebase.get ('Students',str('Asmaa'))
control=firebase.put('Students',str('Asmaa'), get_data+1)
get_data= firebase.get ('Students',str('Asmaa'))
print (get_data)


