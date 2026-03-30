from flask import Flask, jsonify

app = Flask(__name__)

@app.route('/api/temperature', methods=['GET'])
def get_temperature():
    # Placeholder logic for temperature retrieval
    return jsonify({'temperature': 20.5})

app.run(host='0.0.0.0', port=5000)