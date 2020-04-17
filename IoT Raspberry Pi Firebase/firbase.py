import firebase_admin
from firebase_admin import credentials
from firebase_admin import db


cred = credentials.Certificate("auth.json")
#default_app =firebase_admin.initialize_app(cred)
#print(default_app.name)

# Initialize the app with a service account
default_app=firebase_admin.initialize_app(cred, {'databaseURL': '<firebase database url>'})
print(default_app.name)


ref = db.reference('/')
ref.set({
        'Home':
            {
                'Hall': {
                    'light': 'on',
                    'wallLight': "off",
                    'fan': 'on',
					'ac': 'off',

                },
                'Room1': {
					'light': 'on',
                    'wallLight': "off",
                    'fan': 'on',
					'ac': 'off',
                },
				'Room2': {
					'light': 'on',
                    'wallLight': "off",
                    'fan': 'on',
					'ac': 'off',
                },
				'Room3': {
					'light': 'on',
                    'wallLight': "off",
                    'fan': 'on',
					'ac': 'off',
                },
				'Kitchen': {
                    'light': 'on',
                    'exhaustFan': "off",
                    'stove': 'on',
					'socket': 'off',
                },
				'Outdoor': {
                    'waterPump': 'on',
                    'light1': "off",
                    'borewellPump': 'on',
					'light2': 'off',
                }

            }
        })




#updating data
ref = db.reference('Home')
box_ref = ref.child('Outdoor')
box_ref.update({
    'waterPump': 'off'
})


#working with mullti path update

ref = db.reference('Home')
ref.update({
    'Kitchen/light': 'on',
    'Outdoor/borewellPump': 'off'
})


#adding data in second way you can create the key


ref = db.reference('Home')
# Generate a reference to a location 
emp_ref = ref.push({
    'Technology': 'IoT',
    'Home': "UmbrellaPix",
    'Device': 'RapsberryPI'

})

# Get the unique key generated
emp_key = emp_ref.key
print(emp_key)



#retreiving data

ref = db.reference('Home')
print(ref.get())