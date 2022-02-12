print("Blin maker starting up... Initializing... PC on fire... Fire is out... Blin maker is ready.")
bliniCount = input("Enter amount of blini:\n")
print("Recipe Generating...")

waterCups = int(bliniCount) / 4
flourCups = int(bliniCount)
tablespoonSugar = int(bliniCount) / 2
teaspoonBakingSoda = int(bliniCount) / 8
teaspoonSalt = int(bliniCount) / 12
milkCups = int(bliniCount) * 1.0625
butterCups = int(bliniCount) / 12
tablespoonVegetableOil = int(bliniCount) * .75
teaspoonCitricAcidPowder = int(bliniCount) / (4 * 1 / 8)

print("Cups of Water: " + str(waterCups))
print("Cups of Flour: " + str(flourCups))
print("Tablespoons of Sugar: " + str(tablespoonSugar))
print("Teaspoons of Baking Soda: " + str(teaspoonBakingSoda))
print("Teaspoons of Salt: " + str(teaspoonSalt))
print("Cups of Milk: " + str(milkCups))
print("Cups of Butter: " + str(butterCups))
print("Tablespoonds of Vegetable Oil: " + str(tablespoonVegetableOil))
print("Teaspoons of Citric Acid Powder: " + str(teaspoonCitricAcidPowder))