import firebase_admin
from firebase_admin import credentials
from firebase_admin import db


cred = credentials.Certificate("auth.json")
default_app=firebase_admin.initialize_app(cred, {'databaseURL': '<firebase database url>'})
print(default_app.name)

#update or create json table with below data.

dbref = db.dbreference('/')
dbref.set({
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




#updating data particular to one node
dbref = db.dbreference('Home')
box_dbref = dbref.child('Outdoor')
box_dbref.update({
    'waterPump': 'off'
})


#Update multiple data at a time
# ---- use this logic to update the data retrieved from the sensor ( DHT 11/12 , Barometer , Gas sensor)
dbref = db.dbreference('Home')
dbref.update({
    'Kitchen/light': 'on',
    'Outdoor/borewellPump': 'off'
})


dbref = db.dbreference('Home')
# Generating key randomly and insert new data mentioned down
emp_dbref = dbref.push({
    'Technology': 'IoT',
    'Home': "UmbrellaPix",
    'Device': 'RapsberryPI'

})

# Randomly generated unique key and will be used in the program dynamically can be used.
emp_key = emp_dbref.key
print(emp_key)



# Get the data and displayed in the console. i.e. Home will display entire json and home/outdoor will display only that child node.
#---- Use this logic to get the input from firebase db and control the appliances
dbref = db.dbreference('Home')
print(dbref.get())
