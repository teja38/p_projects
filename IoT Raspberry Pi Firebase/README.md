1. Create firebase account
2. Generate new private key and provide that in the cred section in the code.
3. Provide the database url in the given code.
4. pip install firebase-admin
5. python3 firebase.py

Sample code 
-------------------------------------------
import firebase_admin
from firebase_admin import credentials

cred = credentials.Certificate("path/to/serviceAccountKey.json")
firebase_admin.initialize_app(cred)
