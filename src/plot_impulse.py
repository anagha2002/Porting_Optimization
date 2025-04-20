import matplotlib.pyplot as plt

with open("impulse_response.txt", "r") as f:
    data = [float(line.strip()) for line in f]

plt.plot(data)
plt.title("Impulse Response of Parametric Equalizer")
plt.grid(True)
plt.show()
