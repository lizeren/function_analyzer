# Give target feature vector, this python script find the top 3 most similar candidates based on their Euclidean distances 
# from the decompiled target vector,
import json
import numpy as np

# Define the target vector
target_vector = np.array([6,32,24,3,20])

# Load JSON data from a file
with open('output/dec_feature.json', 'r') as file:
    data = json.load(file)

vectors = []
function_names = []

for entry in data:
    vectors.append(entry["vector"])
    function_names.append(entry["function_name"])

# Convert list of vectors to a NumPy array
vectors = np.array(vectors)

# Calculate Euclidean distances between the target vector and all vectors in the JSON
distances = np.linalg.norm(vectors - target_vector, axis=1)

# Get indices of the top 3 smallest distances
top3_indices = np.argsort(distances)[:3]

# Output the top 3 most similar vectors and their distances
print("Top 3 most similar functions and their distances:")
for index in top3_indices:
    print(f"Function: {function_names[index]}, Vector: {vectors[index]}, Distance: {distances[index]}")
